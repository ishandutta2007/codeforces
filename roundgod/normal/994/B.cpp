/*************************************************************************
    > File Name: 2B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 17:21:29
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
typedef pair<ll,ll> P;
ll n,k,c[MAXN];
P a[MAXN];
ll ans[MAXN];
multiset<ll> s;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&c[i]);
        ans[i]=c[i];
    }
    for(ll i=0;i<n;i++)
    {
        if((int)s.size()<k)
        {
            ll sum=0;
            for(auto it=s.begin();it!=s.end();it++)
                sum+=(*it);
            ans[a[i].S]+=sum;
        }
        else
        {
            if(k==0) continue;
            ll sum=0;
            auto it=s.end();
            it--;
            ll cnt=0;
            for(;;it--)
            {
                sum+=(*it);
                cnt++;
                if(cnt==k) break;
            }
            ans[a[i].S]+=sum;
        }
        s.insert(c[a[i].S]);
    }
    for(ll i=0;i<n;i++)
        printf("%lld ",ans[i]);
    return 0;
}