/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-24 00:12:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
bool C(ll x)
{
    ll cnt=0,t=n;
    while(t>0)
    {
        ll res=min(x,t);
        cnt+=res;t-=res;
        t-=t/10;
    }
    //if(x==3) printf("%lld\n",cnt);
    return cnt*2>=n;
}
int main()
{
    scanf("%lld",&n);
    ll l=0,r=n/2+1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%lld\n",r);
    return 0;
}