#include<bits/stdc++.h>
#define llu long long unsigned
using namespace std;
int main(){
   string s;
   cin>>s;
   llu int l=0,r=0,p=0;
   
   
   for(llu int i=0;s[i]!='\0';i++){
    if(s[i]=='^') p=i;
   }
   for(llu int i=0;s[i]!='\0';i++){
       if(i<p && isdigit(s[i])){
          l+=(s[i]-'0')*(p-i);
       }
       else if(isdigit(s[i])){
           r+=(s[i]-'0')*(i-p);
       } 
   }
   if(l==r) cout<<"balance"<<endl;
   else if(l>r) cout<<"left"<<endl;
   else cout<<"right"<<endl;
}