#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2e5+50,P=300,inf=1e18;
ll n,x,y,tot=0,ans=inf;
ll a[N],dy[N];
ll dis[P],ex[P],ey[P];
bool e[P][P];
queue<ll> que;
int main()
{
	ll i,j,s,t,x,v;
	n=rd();
	for(i=1;i<=n;i++) a[i]=rd();
	for(i=0;i<=61;i++)
	{
		x=y=-1;
		for(j=1;j<=n;j++)
		{
			if(a[j]&(1ll<<i))
			{
				if(x==-1) x=j;
				else if(y==-1) y=j;
				else 
				{
					puts("3");
					return 0;
				}
			}
		}
		if(x!=-1&&y!=-1) 
		{
			if(!dy[x]) dy[x]=++tot;
			if(!dy[y]) dy[y]=++tot;
			e[dy[x]][dy[y]]=e[dy[y]][dy[x]]=1;
		}
	}
	for(s=1;s<=tot;s++)
	for(t=s+1;t<=tot;t++)
	{
		if(!e[s][t]) continue;
		memset(dis,0,sizeof(dis));
		dis[s]=1;
		e[s][t]=e[t][s]=0;
		while(!que.empty()) que.pop();
		que.push(s);
		while(!que.empty())
		{
			x=que.front();que.pop();
			if(x==t)
			{
				ans=min(ans,dis[x]);
				break;
			}
			for(v=1;v<=tot;v++)
			{
				if(e[x][v]==1&&dis[v]==0)
				{
					dis[v]=dis[x]+1;
					que.push(v);
				}
			}
		}
		e[s][t]=e[t][s]=1;
	}
	if(ans==inf) puts("-1");
	else printf("%I64d",ans);
	return 0;
}