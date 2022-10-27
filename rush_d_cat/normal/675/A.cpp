#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
int main()
{
    __int64 a,b,c;
    cin>>a>>b>>c;
    if(a==b) cout<<"YES"<<endl;
    else if(c==0) cout<<"NO"<<endl;
    else if((b-a)%c==0){
        if((b-a)*c>0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}