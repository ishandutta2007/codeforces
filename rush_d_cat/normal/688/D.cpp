#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
ll num[1000000+10];
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    ll m,n;cin>>n>>m;
    ll tmp=1,t=1;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&num[i]);
        tmp=lcm(tmp,num[i])/t;
        tmp=gcd(tmp,m);
    } 
    if(tmp==m) cout<<"Yes";
    else cout<<"No";
}