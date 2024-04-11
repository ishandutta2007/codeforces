#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
const int maxn = 200000;
ll a[maxn];
ll f(ll x){
    ll res=0;int tmp=2;
    while(a[tmp]<=x){
        res+=x/a[tmp];tmp++;
    }
    return res;
}
int main()
{
    ll n;cin>>n;
    for(ll i=1;i<=maxn;i++) a[i]=i*i*i;
    ll l=1,r=1e15*8,mid=(l+r)/2;
    while(r-l>1){
        mid=(l+r)/2;
        if(f(mid)>=n) r=mid;
        else l=mid;
    }
    if(f(r)==n) cout<<r<<endl;
    else cout<<-1<<endl;
    return 0;
}