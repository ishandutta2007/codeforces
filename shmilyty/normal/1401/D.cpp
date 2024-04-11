#include<bits/stdc++.h>
#define MAXN 200010
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct EDGE
{
	ll nxt,to;
}edge[MAXN<<1];
ll q,n,m,p[MAXN],head[MAXN],siz[MAXN],t[MAXN],tot,ans;
void add_edge(ll u,ll v)
{
	edge[++tot].nxt=head[u];
	edge[tot].to=v;
	head[u]=tot;
}
void init(){
    memset(edge,0,sizeof(edge));
    memset(t,0,sizeof(t));
    memset(p,0,sizeof(p));
    memset(head,0,sizeof(head));
    tot=0;ans=0;
}
void dfs(ll u,ll fa)
{
    siz[u]=1;
    for(int i=head[u];i;i=edge[i].nxt)
	{
        ll v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    t[u]=siz[u]*(n-siz[u]); 
}
int main()
{
    cin>>q;
    while(q--)
	{
        init();
        cin>>n;
        for(int i=1;i<n;i++)
		{
            ll u,v;
            cin>>u>>v;
            add_edge(u,v);
            add_edge(v,u);
        }
        cin>>m;
        for(int i=1;i<=m;i++)cin>>p[i];
        dfs(1,0); 
        for(int i=m+1;i<n;i++)p[i]=1;
        sort(p+1,p+max(n-1,m)+1);  
        for(int i=n;i<=m;i++) 
            p[n-1]=(p[n-1]*p[i])%mod;
        sort(t+2,t+n+1);  
        for(int i=n-1;i>=1;i--) 
            ans=(ans+p[i]%mod*t[i+1]%mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}