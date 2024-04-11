#include <bits/stdc++.h>
using namespace std;
int main(){
 
       string s;
       cin>>s;
       int check=1;
       for (int i=0;s[i]!='\0';i++){
           if (s[i]!='1'){
               if(s[i]=='4' && ((s[i-1]=='1') ||((s[i-1]=='4') &&(s[i-2]=='1')))){
                   check=1;
               }
               else{
                   check=0;
                   break;
               }


           }
    
       }

     if(check==1){
         cout<<"YES"<<endl;

     }
  else{
      cout<<"NO"<<endl;
  }
    return 0;
}