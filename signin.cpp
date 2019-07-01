#include <bits/stdc++.h>
#include <windows.h>
#include <cstdio>
#include "signin.h"
#include <conio.h>
#include <time.h>
#include "bank.h"
//#include "BankPersonnel.hpp"
//#include "baseuser.h"
#include "uitool.h"
using namespace std;

void SignIn::Init_Signin_UI(){
    //界面
    system("cls");
    for (int i = 1; i <= 60; ++i){
        setCursorLocation(i, 1);
        cout << "=";
        Sleep(10);
    }
    for (int i = 2; i <= 30; ++i){
        setCursorLocation(1, i);
        cout << "||";
        setCursorLocation(59, i);
        cout << "||";
        Sleep(10);
    }
    for (int i = 2; i <= 58; ++i){
        setCursorLocation(i, 30);
        cout << "=";
        Sleep(10);
    }

    setCursorLocation(13, 8);
    setBackgroundColor();
    cout << "Sign In UI";
}

void SignIn::User_Opertation_UI(){
//User 操作界面
}

void SignIn::Manager_Operation_UI(){
//Manager操作界面
}

bool SignIn::JudgeType(){
    bool usertype = false;
    while(islocked){
            setCursorLocation(13, 10);//输入ID 密码 并记录在ID KEY中
            setTextColor(3);
            cout << "Type In ID";

            setCursorLocation(16, 11);
            cin >> ID;

            setCursorLocation(13, 14);
            
            char* password;
            int length=6;
        	password =new char[7];
        	int count=0;
        	char* p =NULL;
        	
        	cout << "Type In Key, then Type In Enter to Confirm";
        	
        	p=password;
        	count=0;
        	
            setCursorLocation(16, 15);
            while (((*p = getch()) != 13) && count < length) {
                
                putch('*');
                fflush(stdin);
 
                p++;
                count++;
        	}
        	password[count]='\0';
        	
        	Key = password;
            //cout << Key;
            islocked = false;

    /*
        ========调用API===========
        正确则islocked=false
        ===========================
    */
            int kk=bank.login(ID, Key);
            if(kk==-1)
                islocked = true;
            else if(kk==0){//用户
                 usertype = true;
                 islocked = false;
            }
            else if(kk==1){//管理员
                usertype = false;
                islocked = false;
            }
               
            if(islocked){
                setCursorLocation(13, 9);
                cout << "ID or Key error! Please Type In Again!";
                system("Pause");
                system("cls");
            }
            else{
                setCursorLocation(13, 9);
                //数据库查找返回usertype user则为true;

                usertype = false;
                if(usertype){//user
                    cout << "User Load In Successfully!";
                }
                else cout<<"Manager Load In Successfully!";
                
                system("Pause");
                system("cls");
                
            }
    }
    //islocked = false;
    //usertype =true;
    return usertype;
}

User* SignIn::ReturnUser(){
    User *usr = NULL;
    usr = bank.seeInfo();
    //User *usr = new User(ID, Key);
    /*
    ========================
    通过数据库API返回用户指针 
    ========================
    */
    return usr;
}

Manager* SignIn::ReturnManager(){
    Manager *usr=NULL;
    
   /*
   ===========================
   通过数据库API返回管理员指针 
   ===========================
   */
   
    return usr;
};

int SignIn::UserChoice(){
    system("cls");
    for (int i = 1; i <= 60; ++i){
        setCursorLocation(i, 1);
        cout << "=";
        Sleep(10);
    }
    for (int i = 2; i <= 30; ++i){
        setCursorLocation(1, i);
        cout << "||";
        setCursorLocation(59, i);
        cout << "||";
        Sleep(10);
    }
    for (int i = 2; i <= 58; ++i){
        setCursorLocation(i, 30);
        cout << "=";
        Sleep(10);
    }
    
    setTextColor(3);
    setCursorLocation(13,7);
    std::cout <<"Use Direction Key to Choose Mode ";
    setCursorLocation(13, 8);
    std::cout <<"And Tap Enter to Confirm:";

    setCursorLocation(13,10);
    setBackgroundColor();
    cout << ">1.Deposite Money";

    setTextColor(3);
    setCursorLocation(13,11);
    cout << "2.Withdraw_Money";
    
    setTextColor(3);
    setCursorLocation(13,12);
    cout << "3.Add_Info";

    setTextColor(3);
    setCursorLocation(13,13);
    cout << "4.Delete_Info";

    setTextColor(3);
    setCursorLocation(13,14);
    cout << "5.Modify_Info";

    setTextColor(3);
    setCursorLocation(13,15);
    cout << "6.Report_Loss";

    setTextColor(3);
    setCursorLocation(13,16);
    cout << "7.Relate_Account";

    setTextColor(3);
    setCursorLocation(13,17);
    cout << "8.Retrieve_Password";
    
    setTextColor(3);
    setCursorLocation(13,18);
    cout << "9.Transfer_Money";

    setTextColor(3);
    setCursorLocation(13,19);
    cout << "10.Logout";

    setTextColor(3);
    setCursorLocation(13,20);
    cout << "11.Exit";

    int choice=1; 
    bool isenter=false;
     /*这插入一个选择函数 ,选择要进行操作的类型并返回相应序号*/
    int ch=1;
    while(ch=getch()){
        switch(ch){
            case 72:
                if(choice>1){
                    switch(choice){
                        case 2:
                            setCursorLocation(13,10);
                            setBackgroundColor();
                            cout << ">1.Deposite Money";

                            setTextColor(3);
                            setCursorLocation(13,11);
                            cout << "2.Withdraw_Money ";
                            --choice;
                            break;

                        case 3:
                        
                            setCursorLocation(13,11);
                            setBackgroundColor();
                            cout << ">2.Withdraw_Money";
                            
                            setTextColor(3);
                            setCursorLocation(13,12);
                            cout << "3.Add_Info ";
                            --choice;
                            break;

                        case 4:
                            
                            setCursorLocation(13,12);
                            setBackgroundColor();
                            cout << ">3.Add_Info";

                            setTextColor(3);
                            setCursorLocation(13,13);
                            cout << "4.Delete_Info ";   
                            --choice;
                            break;

                        case 5:
                            
                            setCursorLocation(13,13);
                            setBackgroundColor();
                            cout << ">4.Delete_Info";

                            setTextColor(3);
                            setCursorLocation(13,14);
                            cout << "5.Modify_Info ";        
                            --choice;
                            break;       

                        case 6:
                            
                            setCursorLocation(13,14);
                            setBackgroundColor();
                            cout << ">5.Modify_Info";

                            setTextColor(3);
                            setCursorLocation(13,15);
                            cout << "6.Report_Loss ";        
                            --choice;
                            break;

                        case 7:

    
                            setCursorLocation(13,15);
                            setBackgroundColor();
                            cout << ">6.Report_Loss";

                            setTextColor(3);
                            setCursorLocation(13,16);

                            cout << "7.Relate_Account ";
                            --choice;
                            break;

                        case 8:
                            
                            setCursorLocation(13,16);
                            setBackgroundColor();
                            cout << ">7.Relate_Account";

                            setTextColor(3);
                            setCursorLocation(13,17);
                            cout << "8.Retrieve_Password ";
                            --choice;
                            break;

                        case 9:
                            
                            setCursorLocation(13,17);
                            setBackgroundColor();
                            cout << ">8.Retrieve_Password";
                            
                            setTextColor(3);
                            setCursorLocation(13,18);
                            cout << "9.Transfer_Money ";
                            --choice;
                            break; 

                        case 10:
                            
                            setCursorLocation(13,18);
                            setBackgroundColor();
                            cout << ">9.Transfer_Money";

                            setTextColor(3);
                            setCursorLocation(13,19);
                            cout << "10.Logout ";
                            --choice;
                            break;
                        case 11:
                            
                            setCursorLocation(13,19);
                            setBackgroundColor();
                            cout << ">10.Logout";

                            setTextColor(3);
                            setCursorLocation(13,20);
                            cout << "11.Exit ";
                            --choice;
                            break;                   
                    
       
                    }
                }
                break;
            case 80://downward
                if(choice <11){
                    switch(choice){
                        case 1:
                            setCursorLocation(13,10);
                            setTextColor(3);
                            cout << "1.Deposite Money ";

                            setCursorLocation(13,11);
                            setBackgroundColor();
                            cout << ">2.Withdraw_Money";
                            ++choice;
                            break;

                        case 2:
                        
                            setCursorLocation(13,11);
                            setTextColor(3);
                            cout << "2.Withdraw_Money ";
                            
                            setCursorLocation(13,12);
                            setBackgroundColor();
                            cout << ">3.Add_Info";
                            ++choice;
                            break;

                        case 3:
                            
                            setCursorLocation(13,12);
                            setTextColor(3);
                            cout << "3.Add_Info ";

                            setBackgroundColor();
                            setCursorLocation(13,13);
                            cout << ">4.Delete_Info";   
                            ++choice;
                            break;

                        case 4:
                            
                            setCursorLocation(13,13);
                            setTextColor(3);
                            cout << "4.Delete_Info ";

                            setBackgroundColor();
                            setCursorLocation(13,14);
                            cout << ">5.Modify_Info";        
                            ++choice;
                            break;       

                        case 5:
                            
                            setCursorLocation(13,14);
                            setTextColor(3);
                            cout << "5.Modify_Info ";

                            setBackgroundColor();
                            setCursorLocation(13,15);
                            cout << ">6.Report_Loss";        
                            ++choice;
                            break;

                        case 6:

    
                            setCursorLocation(13,15);
                            setTextColor(3);
                            cout << "6.Report_Loss ";

                            setBackgroundColor();
                            setCursorLocation(13,16);
                            cout << ">7.Relate_Account";
                            ++choice;
                            break;

                        case 7:
                            
                            setCursorLocation(13,16);
                            setTextColor(3);
                            cout << "7.Relate_Account ";

                            setBackgroundColor();
                            setCursorLocation(13,17);
                            cout << ">8.Retrieve_Password";
                            ++choice;
                            break;

                        case 8:
                            
                            setCursorLocation(13,17);
                            setTextColor(3);
                            cout << "8.Retrieve_Password ";
                            
                            setBackgroundColor();
                            setCursorLocation(13,18);
                            cout << ">9.Transfer_Money";
                            ++choice;
                            break; 

                        case 9:
                            
                            setCursorLocation(13,18);
                            setTextColor(3);
                            cout << "9.Transfer_Money ";

                            setBackgroundColor();
                            setCursorLocation(13,19);
                            cout << ">10.Logout";
                            ++choice;
                            break;
                        case 10:
                            
                            setCursorLocation(13,19);
                            setTextColor(3);
                            cout << "10.Logout ";

                            setBackgroundColor();
                            setCursorLocation(13,20);
                            cout << ">11.Exit";
                            ++choice;
                            break;   
                    }
                }
                break;
            case 13:
                isenter = true;
                break;
            default:
                break;
        }
        if(isenter)
            break;
    }
    setCursorLocation(39, 31);
    return choice;
}

int SignIn::ManagerChoice(){
    system("cls");
    for (int i = 1; i <= 60; ++i){
        setCursorLocation(i, 1);
        cout << "=";
        Sleep(10);
    }
    for (int i = 2; i <= 30; ++i){
        setCursorLocation(1, i);
        cout << "||";
        setCursorLocation(59, i);
        cout << "||";
        Sleep(10);
    }
    for (int i = 2; i <= 58; ++i){
        setCursorLocation(i, 30);
        cout << "=";
        Sleep(10);
    }
    
    setTextColor(3);
    setCursorLocation(13,7);
    std::cout <<"Use Direction Key to Choose Mode ";
    setCursorLocation(13, 8);
    std::cout <<"And Tap Enter to Confirm:";

    setCursorLocation(13,10);
    setBackgroundColor();
    cout << ">1.Verify_New_Account";

    setTextColor(3);
    setCursorLocation(13,11);
    cout << "2.Process_Report_Loss";
    
    setTextColor(3);
    setCursorLocation(13,12);
    cout << "3.Pro_Relate_Account";

    setTextColor(3);
    setCursorLocation(13,13);
    cout << "4.Process_Appeal";

    setTextColor(3);
    setCursorLocation(13,14);
    cout << "5.Process_Logout";

    setTextColor(3);
    setCursorLocation(13,15);
    cout << "6.Exit";

    int choice=1; 
    bool isenter=false;
     /*这插入一个选择函数 ,选择要进行操作的类型并返回相应序号*/
    int ch=1;
    while(ch=getch()){
        switch(ch){
            case 72://up
                if(choice>1){
                    switch(choice){
                        case 2:
                            setCursorLocation(13,10);
                            setBackgroundColor();
                            cout << ">1.Verify_New_Account";

                            setTextColor(3);
                            setCursorLocation(13,11);
                            cout << "2.Process_Report_Loss ";
                            --choice;
                            break;
                        case 3:
                            setCursorLocation(13,11);
                            setBackgroundColor();
                            cout << ">2.Process_Report_Loss";

                            setTextColor(3);
                            setCursorLocation(13,12);
                            cout << "3.Pro_Relate_Account ";
                            --choice;
                            break;
                        case 4:
                            setCursorLocation(13,12);
                            setBackgroundColor();
                            cout << ">3.Pro_Relate_Account";

                            setTextColor(3);
                            setCursorLocation(13,13);
                            cout << "4.Process_Appeal ";
                            --choice;
                            break;
                        case 5:
                            setCursorLocation(13,13);
                            setBackgroundColor();
                            cout << ">4.Process_Appeal";

                            setTextColor(3);
                            setCursorLocation(13,14);
                            cout << "5.Process_Logout ";
                            --choice;
                            break;                        
                        case 6:
                            setCursorLocation(13,14);
                            setBackgroundColor();
                            cout << ">5.Process_Logout";

                            setTextColor(3);
                            setCursorLocation(13,15);
                            cout << "6.Exit ";
                            --choice;
                            break;         
                    }
                }
                break;
            case 80://downward
                if(choice <6){
                    switch(choice){
                        case 1:
                            setCursorLocation(13,10);
                            setTextColor(3);
                            cout << "1.Verify_New_Account ";

                            setCursorLocation(13,11);
                            setBackgroundColor();
                            cout << ">2.Process_Report_Loss";
                            ++choice;
                            break;                   
                        case 2:
                            setCursorLocation(13,11);
                            setTextColor(3);
                            cout << "2.Process_Report_Loss ";

                            setCursorLocation(13,12);
                            setBackgroundColor();
                            cout << ">3.Pro_Relate_Account";
                            ++choice;
                            break;                             
                        case 3:
                            setCursorLocation(13,12);
                            setTextColor(3);
                            cout << "3.Pro_Relate_Account ";

                            setCursorLocation(13,13);
                            setBackgroundColor();
                            cout << ">4.Process_Appeal";
                            ++choice;
                            break;                              
                        case 4:
                            setCursorLocation(13,13);
                            setTextColor(3);
                            cout << "4.Process_Appeal ";

                            setCursorLocation(13,14);
                            setBackgroundColor();
                            cout << ">5.Process_Logout";
                            ++choice;
                            break; 
                        case 5:
                            setCursorLocation(13,14);
                            setTextColor(3);
                            cout << "5.Process_Logout ";

                            setCursorLocation(13,15);
                            setBackgroundColor();
                            cout << ">6.Exit";
                            ++choice;
                            break;                         
                    }
                }
                break;
           case 13:
               setTextColor(3);
               isenter = true;
               break;
            default:
                break;
        }
        if(isenter)
            break;
    }
    setCursorLocation(39, 31);
    return choice;
}


void SignIn::UserSignin(){
    setTextColor(3);
    User_Opertation_UI();
    int choice = UserChoice();
    bool Continue = true;
    while(choice){
        switch (choice)
        {
        case 1:
            Deposite_Money();
            break;
        case 2:
            Withdraw_Money();
            break;
        case 3:
            Add_Info();
            break;
        case 4:
            Delete_Info();
            break;
        case 5:
            Modify_Info();
            break;
        case 6:
            Report_Loss();
            break;
        case 7:
            Relate_Account();
            break;
        case 8:
            Retrieve_Password();
            break;
        case 9:
            Tranfer_Money();
            break;
        case 10:
            Logout();
            break;
        case 11:
            bank.signout();
            Continue = false;
            break;

        default:
            Continue = false;
            break;
        };
        /*是否继续 */
        
        if (Continue){
            choice = UserChoice();
        }
        else{
            setTextColor(3);
            choice = 0;
            break;
        }
    }    
       
}

void SignIn::ManagerSignin(){
    setTextColor(3);
    Manager_Operation_UI();
    int choice = ManagerChoice();
    bool Continue = true;
        while(choice){
            switch (choice)
            {
            case 1:
                Verify_New_Account();
                break;
            case 2:
                Process_Report_Loss();
                break;
            case 3:
                Pro_Relate_Account();
                break;
            case 4:
                Process_Appeal();
                break;
            case 5:
                Process_Logout();
                break;
            case 6:
                Continue = false;
                break;
            default:
                Continue = false;
                break;
            };
            /*是否继续 */
            
            if (Continue){
                setTextColor(3);
                choice = ManagerChoice();
            }
            else{
                choice = 0;
                break;
            }
        }    
}

void SignIn::SigninAction(){
    Init_Signin_UI();
    if(JudgeType()){//判定用户类型
        if(!islocked){
            //User *usr = ReturnUser(ID,Key);
            // if(usr==NULL){
            //     setCursorLocation(13, 24);
            //     cout << "Load User Failed.";
            //     system("Pause");
            // }
            // else  {
            UserSignin();

            //}    
        }   
    }
    else{
        if(!islocked){
            //Manager *usr = ReturnManager(ID, Key);
            // if(usr==NULL){
            //     setCursorLocation(13, 24);
            //     cout << "Load Manager Failed";
			// 	system("Pause");
            // }
            //else 
            ManagerSignin();//管理员登陆

        }
    }
}

void SignIn::Deposite_Money(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Please Type In the Ammount ";
    setCursorLocation(13, 12);
    cout << "You Want To Deposite.";
    setCursorLocation(13, 13);
    string Amount="";
    cin >> Amount;
    bool is_success = false;
    is_success = bank.depositeMoney(Amount);
    if(is_success){
        setCursorLocation(13, 14);
        cout << "Successfully Deposite Money";
    }
    else{
        setCursorLocation(13, 14);
        cout << "Failed to Deposite Money";
    }
    system("Pause");
}

void SignIn::Withdraw_Money(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Please Type In the Ammount ";
    setCursorLocation(13, 12);
    cout << "You Want To Withdraw.";
    setCursorLocation(13, 13);
    string Amount="";
    cin >> Amount;
    bool is_success = false;
    is_success = bank.withdrawMoney(Amount);
    if(is_success){
        setCursorLocation(13, 14);
        cout << "Successfully Withdraw Money";
    }
    else{
        setCursorLocation(13, 14);
        cout << "Failed to Withdraw Money";
    }
    system("Pause");
}

void SignIn::Add_Info(){
	system("cls");
    setCursorLocation(13,9);
    cout << "Type In the type of information you want to Add";
    setCursorLocation(13, 10);
    cout << "1.phone, 2.email, 3.address, 4.zip";
    setCursorLocation(13, 11);
    int Type;
    cin >> Type;

    setCursorLocation(13, 12);
    if(Type==1){
        cout << "Phone Num:";
    }
    else if(Type==2){
        cout << "Email Address:";

    }else if(Type==3){
        cout << "Home Address:";
    }
    else if(Type==4){
        cout << "Zip Code:";
    }
    setCursorLocation(13, 13);
    cout << "Type In the Added information";
    string info;
    cin >> info;
    bool is_added=bank.alterInfo(Type, info);
    if(is_added){
        setCursorLocation(13, 14);
        cout << "Successfully Add Information";
    }
    else {
        setCursorLocation(13, 15);
        cout << "Failed to Add Information";
    }
    system("Pause");
}
void SignIn::Delete_Info(){
	system("cls");
    setCursorLocation(13,9);
    cout << "Type In the type of information you want to Delete";
    setCursorLocation(13, 10);
    cout << "1.phone, 2.email, 3.address, 4.zip";
    setCursorLocation(13, 11);
    int Type;
    cin >> Type;
    setCursorLocation(13, 12);
    if(Type==1){
        cout << "Phone Num:";
    }
    else if(Type==2){
        cout << "Email Address:";

    }else if(Type==3){
        cout << "Home Address:";
    }
    else if(Type==4){
        cout << "Zip Code:";
    }
    setCursorLocation(13, 13);
    string info = "";
    bool is_deleted=bank.alterInfo(Type, info);
    if(is_deleted){
        setCursorLocation(13, 14);
        cout << "Successfully Delete Information";
    }
    else {
        setCursorLocation(13, 15);
        cout << "Failed to Delete Information";
    }
    system("Pause");
}
void SignIn::Modify_Info(){
    system("cls");
    setCursorLocation(13,9);
    cout << "Type In the type of information you want to modify";
    setCursorLocation(13, 10);
    cout << "1.phone, 2.email, 3.address, 4.zip";
    setCursorLocation(13, 11);
    int Type;
    cin >> Type;
    setCursorLocation(13, 12);
    if(Type==1){
        cout << "Phone Num:";
    }
    else if(Type==2){
        cout << "Email Address:";

    }else if(Type==3){
        cout << "Home Address:";
    }
    else if(Type==4){
        cout << "Zip Code:";
    }
    setCursorLocation(13, 13);
    cout << "Type In the motified information";
    string info;
    cin >> info;
    bool is_motified=bank.alterInfo(Type, info);
    if(is_motified){
        setCursorLocation(13, 14);
        cout << "Successfully Motify Information";
    }
    else {
        setCursorLocation(13, 15);
        cout << "Failed to Motify Information";
    }
    system("Pause");
}



void SignIn::Report_Loss(){

    system("cls");
    setCursorLocation(13,10);
    cout << "Type In *1* to Report_Loss ";
    setCursorLocation(13, 11);
    cout << "Type In *2* to REVERT Report Loss";
    setCursorLocation(13, 12);
    int choice;
    cin >> choice;
    bool is_success;
    setCursorLocation(13, 13);
    if(choice==1){
        cout << "Type in Your Lost ID Card Number";
        string card;
        cin >> card;
         is_success=bank.reportCardLoss(card);
    }
    else if(choice==2){
    	cout << "Type in The ID Card Number to be revert RCL";
        string card;
        cin >> card;
        is_success =bank.revertReportCardLoss(card);
    }
    if(is_success){
        cout << "Successfully Operated";
    }
    else
        cout << "Operation Failed";

    system("Pause");
	
}
void SignIn::Relate_Account(){
	system("cls");
    setCursorLocation(13, 9);
    cout << "Type In *1* if you want to bind accounts";
    setCursorLocation(13, 10);
    cout<<" or *2* if you want to Remove Bingding Relationship ";
    int choice;
    cin >> choice;

    setCursorLocation(13, 12);
    string Card_ID;
    cin >> Card_ID;
    if(choice==1){
        bool is_bound = bank.bindCard(Card_ID);
        setCursorLocation(13, 13);
        if(is_bound){
            cout << "Successfully Relate your Accounts";
        }
        else
            cout << "Relate Accounts Failed";
    }
    else if(choice==2){
        bool is_remove = bank.removeCard(Card_ID);
        setCursorLocation(13, 13);
        if(is_remove){
            cout << "Successfully Remove your Accounts";
        }
        else
            cout << "Remove Relationship Failed";
    }

    system("Pause");
}


void SignIn::Retrieve_Password(){
	system("cls");
    string Key;
    string Key1 = "123123", Key2 = "321321";
    bool is_Same_Key = false;
    while(!is_Same_Key){
            setCursorLocation(13, 9);
            char* password;
            int length=6;
            password =new char[7];
            int count=0;
            char* p =NULL;
                    
            cout << "Type In Key, then Type In Enter to Confirm";
                    
            p=password;
            count=0;
            setCursorLocation(16, 10);
            while (((*p = getch()) != 13) && count < length) {     
                putch('*');
                fflush(stdin);
                p++;
                count++;
            }
            password[count]='\0';
            Key1 = password;

            setCursorLocation(13, 11);
            cout << "Type In Key Again to Confirm";

            p=password;
            count=0;
            setCursorLocation(16, 12);
            while (((*p = getch()) != 13) && count < length) {     
                putch('*');
                fflush(stdin);
                p++;
                count++;
            }
            password[count]='\0';
            Key2 = password;
            if(Key1!=Key2){
                setCursorLocation(13, 8);
                cout << "Diffrent Key";
                setCursorLocation(13, 9);
                cout << "                                            ";
                setCursorLocation(13, 10);
                cout << "                                            ";
                setCursorLocation(13, 11);
                cout << "                                            ";
                setCursorLocation(13, 12);
                cout << "                                            ";
                is_Same_Key=false;
            }
            else{
                is_Same_Key = true;
                Key = Key1;
                break;
            }
                
    }
    bool is_changed = bank.changePassword(Key);
    setCursorLocation(13, 14);
    if(is_changed){
        cout << "Changed Password Successfully";
    }
    else
        cout << "Failed to Change The Password";

    system("Pause");
}

void SignIn::Tranfer_Money(){
    system("cls");
    setCursorLocation(13, 10);
    cout << "Type in The Card-ID that you want to transfer towards";
    setCursorLocation(13, 12);
    
    string card;
    cin >> card;
    
    setCursorLocation(13, 14);
    cout << "Type in The Amount You Want to Transfer";

    setCursorLocation(13, 16);
    string amount;
    cin >> amount;
    
    bool is_successful_tranfer = bank.tranferMoney(card, amount);
    setCursorLocation(13, 18);
    if(is_successful_tranfer){
        cout << "Tranfer Money Successully";
    }
    else{
        cout<< "Tranfer Money ";
    }
    setCursorLocation(13, 20);
    system("Pause");
}
void SignIn::Appeal(){
    system("cls");
    setCursorLocation(13, 10);
    cout << "Type In Your Appeal Content";
    string content;
    setCursorLocation(13, 12);
    cin >> content;
    bank.appeal(content);
    setCursorLocation(13, 13);
    system("Pause");
}

void SignIn::Logout(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Type in *CONFIRM* to confirm logging out";
    string confirm;
    setCursorLocation(13, 11);
    cin >> confirm;
    if(confirm=="CONFIRM"){
        setCursorLocation(13, 12);
        bool is_deleted = bank.deleteUser();

        setCursorLocation(13, 13);
        if(is_deleted){
            cout << "Log Out Successfully" << endl;
        }
        else
            cout << "Failed to Log Out" << endl;
        
    }

    system("Pause");
}

/*Manager 类外实现 */
void SignIn::Verify_New_Account(){
	
    vector<User *> usr;
    bool iscontinue = true;

    while(iscontinue){
        system("cls");
        setCursorLocation(13,10);
        cout << "Loading the List of To-be-verified Users";
        setCursorLocation(13, 11);
        usr = bank.getUnReviewedUser();
        for(auto &user : usr){
            cout << user->id_account << "  " << user->name << endl;
        }
        cout << "Type in the user ID_Account To Verify" << endl;
        string id;
        cin >> id;
        bool isverified = bank.approveUnReviewedUser(id);
        if(isverified){
            cout << "Verified Successfully,type *1* to continue,*2* to exit";
        }
        else  cout << "Verified Failed ,type *1* to continue,*2* to exit";
        int choice;
        cin >> choice;
        if(choice==1)
            iscontinue = true;
        else
            iscontinue = false;
    }
    

    system("Pause");
}
void SignIn::Process_Report_Loss(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Activity Inavailable";
    system("Pause");
}
void SignIn::Pro_Relate_Account(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Activity Inavailable";
    system("Pause");
}
void SignIn::Process_Appeal(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Activity Inavailable";
    system("Pause");
}
void SignIn::Process_Logout(){
	system("cls");
    setCursorLocation(13,10);
    cout << "Activity Inavailable";
    system("Pause");
}
