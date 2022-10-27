#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    __int64 n;cin>>n;
    __int64 res=n/3*2;
    if(n%3!=0) res++;
    cout<<res<<endl;
    return 0;
}