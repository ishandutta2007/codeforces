#include<bits/stdc++.h>
#define N 200005
#define inf 1000000000
#define mid (l+r>>1)
#define ls k<<1
#define rs ls|1
#define pb push_back
using namespace std;
int n,m,q,a[N],dfn[N],low[N],st[N],to[N],hd[N],lk[N],cnt,t,
sz[N],son[N],top[N],f[N],dep[N],b[N<<2],pos[N],np[N];
vector<int>ed[N];
priority_queue<int>Q[N],D[N];
int loc,val;
void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	for(int s,i=lk[x];i;i=hd[i])
	if(!dfn[s=to[i]])
	{
		st[t++]=i;dfs(s);
		low[x]=min(low[x],low[s]);
		if(low[s]>=dfn[x])
		{
			for(ed[x].pb(++n);st[t]^i;)
			ed[n].pb(to[st[--t]]),Q[n].push(-a[to[st[t]]]);
			a[n]=-Q[n].top();
		}
	}
	else low[x]=min(low[x],dfn[s]);
}
void dfss(int x)
{
	sz[x]=1,dep[x]=dep[f[x]]+1;
	for(auto i:ed[x])
    f[i]=x,dfss(i),sz[x]+=sz[i],sz[son[x]]<sz[i]?son[x]=i:0;
}
void ssfd(int x)
{
	np[pos[x]=++cnt]=x,top[x]?0:(top[x]=x);
    if(son[x])top[son[x]]=top[x],ssfd(son[x]);
    for(auto i:ed[x])
	if(i^son[x])ssfd(i);
}
inline void upd(int k)
{b[k]=min(b[ls],b[rs]);}
void build(int k,int l,int r)
{l<r?build(ls,l,mid),build(rs,mid+1,r),upd(k),0:(b[k]=a[np[l]]);}
void mdf(int k,int l,int r)
{l^r?loc>mid?mdf(rs,mid+1,r):mdf(ls,l,mid),upd(k),0:(b[k]=a[np[l]]);}
void qry(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr)val=min(val,b[k]);
	else qry(ls,l,mid,ll,rr),qry(rs,mid+1,r,ll,rr);
}
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
int u,v;
char op[2];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(;m--;)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	cnt=0,m=n;dfs(1);dfss(1);
	cnt=0;ssfd(1),build(1,1,n);
	for(;q--;)
	{
		scanf("%s%d%d",op,&u,&v);
		if(op[0]=='C')
		{
			val=v,v=f[u];
            if(v)
			{
				Q[v].push(-val),D[v].push(-a[u]);
				for(;D[v].size()&&Q[v].top()==D[v].top();Q[v].pop(),D[v].pop());
				a[v]=-Q[v].top(),loc=pos[v],mdf(1,1,n);
			}
			a[u]=val,loc=pos[u],mdf(1,1,n);
		}
		else
		{
			val=inf;
			for(;top[u]^top[v];)
			{
				if(dep[top[u]]<dep[top[v]])swap(u,v);
				qry(1,1,n,pos[top[u]],pos[u]),u=f[top[u]];
			}
			if(dep[u]>dep[v])swap(u,v);
			qry(1,1,n,pos[u],pos[v]),v=f[u];
			if(v<=m)qry(1,1,n,pos[v],pos[v]);
			printf("%d\n",val);
		}
	}
}