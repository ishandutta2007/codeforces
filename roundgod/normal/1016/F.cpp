/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 00:29:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge {ll to,cost;};
ll n,q;
vector<edge> G[MAXN];
ll fa[MAXN],dis[MAXN],len[MAXN],len2[MAXN],len3[MAXN];
bool used[MAXN];
void dfs(ll v,ll p,ll d)
{
    fa[v]=p;
    dis[v]=d;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to,cost=G[v][i].cost;
        if(to==p) continue;
        len[to]=cost;
        dfs(to,v,d+cost);
    }
}
void dfs2(ll v,ll p)
{
    if(!used[v]&&!used[p]) fa[v]=fa[fa[v]];
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to;
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back((edge){v,w});G[v].push_back((edge){u,w});
    }
    dfs(1,0,0);
    memset(used,false,sizeof(used));
    bool f=true;
    ll v=n;
    do
    {
        used[v]=true;
        v=fa[v];
    }while(v!=0);
    dfs2(1,0);
    v=n;
    for(int i=1;i<=n;i++) if(used[i]) len3[fa[i]]=len[i];
    len[1]=len3[n]=INF;
    for(ll i=1;i<=n;i++) if(!used[i]&&(int)G[i].size()>1) f=false;
    for(ll i=1;i<=n;i++) if(!used[i]) len2[fa[i]]=max(len2[fa[i]],len[i]);
    ll last=-1,cnt=0,ans=INF;
    for(int i=1;i<=n;i++) 
    {
        if(used[i]&&i!=1&&fa[i]!=1) ans=min(ans,dis[i]-dis[fa[fa[i]]]);
    }
    while(v!=0)
    {
        if(v!=1&&v!=n)
        {
            if((int)G[v].size()>=4) {f=false; break;}
            if((int)G[v].size()==3)
            {
                ans=min(ans,len[v]-len2[v]);ans=min(ans,len3[v]-len2[v]);
                if(last==-1) {last=len2[v]; cnt=0;}
                else {ans=min(ans,cnt-last-len2[v]); last=len2[v]; cnt=0;}
            }
        }
        else
        {
            if((int)G[v].size()>=3) {f=false; break;}
            if((int)G[v].size()==2)
            {
                ans=min(ans,len[v]-len2[v]); ans=min(ans,len3[v]-len2[v]);
                if(last==-1) {last=len2[v];  cnt=0;}
                else {ans=min(ans,cnt-last-len2[v]); last=len2[v]; cnt=0;}
            }
        }
        cnt+=len[v];
        v=fa[v];
    }
    //printf("%d\n",ans);
    for(ll i=0;i<q;i++)
    {
        ll x;
        scanf("%lld",&x);
        if(x<ans&&f) printf("%lld\n",max(0LL,dis[n]-ans)+x); else printf("%lld\n",dis[n]);
    }
    return 0;
}