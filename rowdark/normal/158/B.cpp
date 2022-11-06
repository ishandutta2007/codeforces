#include<stdio.h>
#include<iostream>
using namespace std;
int ans,S[5],n,j;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>j,++S[j];
    ans=S[4]+S[3];
    S[1]-=S[3];
    if(S[1]<0) S[1]=0;
    ans+=S[2]/2;
    if(S[2]&1) S[1]+=2;
    ans+=(S[1]+3)/4;
    cout<<ans<<endl;
    return 0;
}