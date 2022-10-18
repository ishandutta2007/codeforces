#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
#define fi first
#define se second
int n,m;
#define MAXN 200005
struct eric
{
    int to,next,v;
}edge[MAXN<<1];
int head[MAXN],soze;
void add(int x,int y,int z)
{
    edge[++soze].to=y;
    edge[soze].v=z;
    edge[soze].next=head[x];
    head[x]=soze;
}
ll f[MAXN],g[MAXN],dadlen[MAXN];
void dfs1(int pos,int fa)
{
    g[pos]=0;
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
        continue;
        dadlen[v]=edge[i].v;
        dfs1(v,pos);
        g[pos]=max(g[pos],g[v]+edge[i].v);
    }
}
int stak[MAXN],top;
pair<ll,int> pp[MAXN];
ll ans,lmax[MAXN],rmax[MAXN],maxa[MAXN][3];
void dfs2(int pos,int fa,ll fr,ll maxx,ll amaxx)
{
    // cerr<<pos<<' '<<fr<<endl;
    maxx=max(maxx,amaxx+2*dadlen[pos]);
    top=0;
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
        continue;
        stak[++top]=v;
        pp[top]={g[v]+edge[i].v,v};
        // lmax[top]=max(lmax[top-1],g[v]);
    }
    // rmax[top+1]=0;
    // for(int i=top;i;i--)
    // rmax[i]=max(rmax[i+1],g[stak[i]]);
    sort(pp+1,pp+top+1);pp[top+1]=pp[top+2]={0,0};
    ans=max(ans,maxx+pp[top].fi+(top?pp[top-1].fi:0));
    pp[top+1]={fr,fa};
    sort(pp+1,pp+top+2);
    ll sum=0;
    for(int i=top+1;i>top-3&&i;i--)
    sum+=pp[i].fi;
    ans=max(ans,sum);

    // cerr<<pos<<' '<<top<<' '<<sum<<endl;
    // if(pos==1)
    // for(int i=1;i<=top+1;i++)
    // cerr<<pp[i].fi<<','<<pp[i].se<<' '<<g[pp[i].se]<<endl;

    for(int i=1;i<=top;i++)
    {
        int v=stak[i];
        for(int j=top+1,k=0;j>top-2&&j;j--)
        if(pp[j].se!=v)
        maxa[v][k++]=pp[j].fi;
    }
    for(int i=head[pos];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
        continue;
        if(amaxx>=maxa[v][0]+maxa[v][1])
        dfs2(v,pos,maxa[v][0]+edge[i].v,maxx,amaxx);
        else
        dfs2(v,pos,maxa[v][0]+edge[i].v,maxx,maxa[v][0]+maxa[v][1]);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    ll tott=0;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
        tott+=z<<1;
    }
    dfs1(1,0);
    // cerr<<'&'<<'\n';
    dfs2(1,0,0,0,0);
    cout<<tott-ans<<'\n';
    // cerr<<ans<<endl;
    return 0;
}