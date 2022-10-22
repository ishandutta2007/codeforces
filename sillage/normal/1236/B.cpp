#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define mod 1000000007
using namespace std;
ll n,m;
ll ppow(ll a,ll x)
{
    ll tans=1;
    while(x)
    {
      if(x&1)tans=tans*a%mod;
      a=a*a%mod;x>>=1;
    }
    return tans;
}
int main()
{
    cin >>n>>m;
    cout <<ppow(ppow(2,m)-1,n);
    return 0;
}