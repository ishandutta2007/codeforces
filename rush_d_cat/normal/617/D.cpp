#include<iostream>
#include<math.h>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
int main(){
    ll a[4],b[4];
    for(int i=1;i<=3;i++)
    {
        cin>>a[i]>>b[i];
    }
    if((a[1]==a[2])+(a[2]==a[3])==2||(b[1]==b[2])+(b[2]==b[3])==2)
    {
        cout<<1<<endl;
        return 0;
    }
    if((a[1]==a[2])&&(b[3]>=max(b[1],b[2])||b[3]<=min(b[1],b[2])))
    {
        cout<<2<<endl;
        return 0;
    }
    if((a[2]==a[3])&&(b[1]>=max(b[2],b[3])||b[1]<=min(b[2],b[3])))
    {
        cout<<2<<endl;
        return 0;
    }
    if((a[1]==a[3])&&(b[2]>=max(b[1],b[3])||b[2]<=min(b[1],b[3])))
    {
        cout<<2<<endl;
        return 0;
    }
    if((b[1]==b[2])&&(a[3]>=max(a[1],a[2])||a[3]<=min(a[1],a[2])))
    {
        cout<<2<<endl;
        return 0;
    }
    if((b[2]==b[3])&&(a[1]>=max(a[2],a[3])||a[1]<=min(a[2],a[3])))
    {
        cout<<2<<endl;
        return 0;
    }
    if((b[1]==b[3])&&(a[2]>=max(a[1],a[3])||a[2]<=min(a[1],a[3])))
    {
        cout<<2<<endl;
        return 0;
    }
    cout<<3<<endl;
    return 0;
}