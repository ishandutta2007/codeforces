/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-27 23:02:35
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
ll n,k,a[MAXN];
ll l[MAXN],r[MAXN];
ll len[MAXN],cnt[MAXN],ans[MAXN];
set<ll> s;
map<ll,ll> mp;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) 
    {
        scanf("%lld%lld",&l[i],&r[i]);
        r[i]++;
    }
    for(ll i=0;i<n;i++)
    {
        s.insert(l[i]);
        s.insert(r[i]);
    }
    ll tot=0;
    for(auto it=s.begin();it!=s.end();it++)
        mp[*it]=++tot;
    vector<ll> v(s.begin(),s.end());
    /*for(int i=0;i<v.size();i++)
        printf("%lld ",v[i]);
    puts("");*/
    for(ll i=0;i<n;i++)
    {
        cnt[mp[l[i]]]++;
        cnt[mp[r[i]]]--;
    }
    for(ll i=1;i<=tot;i++)
        cnt[i]+=cnt[i-1];
    /*for(ll i=1;i<=tot;i++)
        printf("%lld\n",cnt[i]);*/
    for(ll i=1;i<tot;i++)
        if(cnt[i]>0) ans[cnt[i]]+=v[i]-v[i-1];
    for(ll i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}