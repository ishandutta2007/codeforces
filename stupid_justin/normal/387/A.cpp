#include<bits/stdc++.h>
using namespace std;
int s,t,p;
string str1,str2;
int main(){
    cin>>str2>>str1;
    s=600*(str1[0]-48)+60*(str1[1]-48)+10*(str1[3]-48)+str1[4]-48;
    t=600*(str2[0]-48)+60*(str2[1]-48)+10*(str2[3]-48)+str2[4]-48;
    p=t-s;
    if(p<0) p+=1440;
    cout<<p/600;
    p%=600;
    cout<<p/60;
    p%=60;
    cout<<":";
    cout<<p/10;
    p%=10;
    cout<<p;
    return 0;
}