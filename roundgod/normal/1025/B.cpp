/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 21:40:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],b[MAXN];
ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
int main()
{
    scanf("%lld",&n);
    ll ans=0;
    for(ll i=0;i<n;i++) 
    {
        scanf("%lld%lld",&a[i],&b[i]);
        ans=gcd(ans,lcm(a[i],b[i]));
    }
    if(ans==1) {puts("-1"); return 0;}
    else 
    {
        ll res=ans;
        for(int i=0;i<n;i++)
        {
            if(gcd(res,a[i])>1) res=gcd(res,a[i]);
            if(gcd(res,b[i])>1) res=gcd(res,b[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}