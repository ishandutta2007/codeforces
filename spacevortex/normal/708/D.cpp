#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=150,E=N*10,inf=1e9;
ll n,m,S,T,cnt=1,ans=0,tim,top,num,W;
ll dis[N],he[N],vis[N],ins[N],stk[N],h[N];
queue<ll> que;
struct Edge
{
	ll v,w,f,nxt;
}e[E];
void eadd(ll u,ll v,ll w,ll f)
{
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].f=f;e[cnt].nxt=he[u];he[u]=cnt;
	cnt++;e[cnt].v=u;e[cnt].w=0;e[cnt].f=-f;e[cnt].nxt=he[v];he[v]=cnt;
}
bool spfa()
{
	ll x,i,v,w,f;
	memset(vis,0,sizeof(vis));
	memset(ins,0,sizeof(ins));
	memset(dis,0x3f,sizeof(dis));dis[S]=0;
	while(!que.empty()) que.pop();que.push(S);ins[S]=1;
	while(!que.empty())
	{
		x=que.front();que.pop();ins[x]=0;
		for(i=he[x];i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;f=e[i].f;
			if(w==0) continue;
			if(dis[x]+f<dis[v])
			{
				dis[v]=dis[x]+f;
				//puts("OK");
				if(!ins[v]) ins[v]=1,que.push(v);
			}
		}
	}
	if(dis[T]<0) return 1;
	else return 0;
}
ll dinic(ll x,ll flow)
{
	if(x==T) return flow;
	ll i,v,w,f,nfl,rest=flow;
	vis[x]=1;
	for(i=he[x];i&&rest;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;f=e[i].f;
		if(dis[x]+f==dis[v]&&vis[v]==0&&w>0)
		{
			nfl=dinic(v,min(w,rest));
			e[i].w-=nfl;e[i^1].w+=nfl;rest-=nfl;
		}
	}
	return flow-rest;
}
bool dfs(ll x)
{
	ll i,v,w,f;
	vis[x]=tim;
	for(i=he[x];i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;f=e[i].f;
		if(w>=W&&dis[x]+f<dis[v])
		{
			dis[v]=dis[x]+f;
			stk[++top]=i;
			if(vis[v]==tim)
			{
				num=0;
				while(true)
				{
					h[++num]=stk[top--];
					if(e[stk[top+1]^1].v==v) break;
				}
				return 1;
			}
			else if(dfs(v)==1) return 1;
			top--;
		}
	}
	vis[x]=0;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,u,v,c,f,nfl,nvl;
	cin>>n>>m;
	S=1;T=n;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>c>>f;
		ans+=f;
		if(f<=c)
		{
			eadd(u,v,inf,2);
			eadd(u,v,c-f,1);
			eadd(u,v,f,-1);
		}
		else
		{
			eadd(u,v,inf,2);
			eadd(u,v,f-c,0);
			eadd(u,v,c,-1);
		}
	}
	for(W=1e6;W>0;W>>=1)
	{
	while(true)
	{
		top=0;num=0;
		memset(dis,0,sizeof(dis));
		for(i=1;i<=n;i++) 
		{
			tim++;
			if(dfs(i)) break;
		}
		if(num==0) break;
		nfl=inf;nvl=0;
		for(i=1;i<=num;i++) nfl=min(nfl,e[h[i]].w),nvl+=e[h[i]].f;
		ans+=nfl*nvl;
		for(i=1;i<=num;i++) e[h[i]].w-=nfl,e[h[i]^1].w+=nfl;
	}
	}
	while(spfa()) 
	{
		ans+=dinic(S,inf)*dis[T];
	}
	cout<<ans;
	return 0;
}