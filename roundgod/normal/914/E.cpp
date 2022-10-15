/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-24 15:58:47
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,root,a[MAXN],sz[MAXN],cnt[1<<20],ans[MAXN],inc[MAXN];
vector<ll> G[MAXN];
bool centroid[MAXN];
P getroot(ll v,ll p,ll t)//search_centroid
{
    P res=P(INT_MAX,-1);
	ll m=0;
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getmask(ll v,ll p,ll mask,ll num)//enumerate path
{
    mask^=(1<<a[v]);
    cnt[mask]+=num;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        getmask(to,v,mask,num);
    }
}
ll check(ll v,ll p,ll mask)
{
    mask^=(1<<a[v]);
    ll res=cnt[mask];
    for(ll i=0;i<20;i++) res+=cnt[mask^(1<<i)];
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        res+=check(to,v,mask);
    }
    ans[v]+=res;
    return res;
}
void solve(ll v)
{
    //printf("%lld\n",v);
    centroid[v]=true;
    getmask(v,0,0,1);
    ll sum=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(centroid[to]) continue;
        getmask(to,v,1<<a[v],-1);
        sum+=check(to,v,0);
        getmask(to,v,1<<a[v],1);
    }
    for(int i=0;i<20;i++) sum+=cnt[1<<i];
    sum+=cnt[0]+1;
    ans[v]+=sum/2;
    getmask(v,0,0,-1);
    //for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
    //puts("");
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        solve(root);
    }
    root=v;
}
void ac()
{
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    memset(centroid,false,sizeof(centroid));
    root=getroot(1,0,n).S;
    solve(root);
    for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
}
string str;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    cin>>str;
    for(ll i=0;i<n;i++) a[i+1]=str[i]-'a';
    ac();
    return 0;
}