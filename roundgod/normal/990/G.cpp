/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-11 10:12:03
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
ll p[MAXN],r[MAXN],sz[MAXN],ans[MAXN];
vector<P> G[MAXN];
vector<int> v[MAXN];
ll cur;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cur-=sz[x]*(sz[x]-1)/2;
    cur-=sz[y]*(sz[y]-1)/2;
    p[x]=y;
    sz[y]+=sz[x];
    cur+=sz[y]*(sz[y]-1)/2;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        v[a[i]].push_back(i);
    }
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[gcd(a[u],a[v])].push_back(P(u,v));
    }
    for(ll i=1;i<=200000;i++)
    {
        cur=0;
        for(ll j=i;j<=200000;j+=i)
        {
            for(ll k=0;k<(int)v[j].size();k++)
            {
                ll node=v[j][k];
                p[node]=node,sz[node]=1;
                cur++;
            }
        }
        for(ll j=i;j<=200000;j+=i)
        {
            for(ll k=0;k<(int)G[j].size();k++)
            {
                P e=G[j][k];
                unite(e.F,e.S);
            }
        }
        ans[i]=cur;
    }
    for(ll i=200000;i>=1;i--)
        for(ll j=2*i;j<=200000;j+=i)
            ans[i]-=ans[j];
    for(ll i=1;i<=200000;i++)
        if(ans[i]) printf("%lld %lld\n",i,ans[i]);
    return 0;
}