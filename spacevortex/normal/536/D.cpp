#include<bits/stdc++.h>
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
typedef long long ll;
const ll N=2050,E=2e5+50;
ll n,m,a,b,cnt=1,tot,num[2],W=0;
ll p[N],he[N],dis[N],d[2][N],h[2][N],pl[N],dp[N][N][2],f[N][N],g[N][N],del[N],pos[N][N][2],mn[N][N][2];
bool ins[N];
struct Edge
{
	ll v,w,nxt;
}e[E];
void eadd(ll u,ll v,ll w)
{
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].nxt=he[u];he[u]=cnt;
	cnt++;e[cnt].v=u;e[cnt].w=w;e[cnt].nxt=he[v];he[v]=cnt;
}
queue<ll> que;
bool cmp(const ll &a,const ll &b){return dis[a]<dis[b];}
void Solve(ll S,ll T,ll tp)
{
	ll x,i,v,w;
	memset(dis,0x3f,sizeof(dis));
	memset(ins,0,sizeof(ins));
	dis[S]=0;ins[S]=1;que.push(S);
	while(!que.empty())
	{
		x=que.front();que.pop();
		ins[x]=0;
		for(i=he[x];i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(dis[x]+w<dis[v])
			{
				dis[v]=dis[x]+w;
				if(!ins[v]) ins[v]=1,que.push(v);
			}
		}
	}
	for(i=1;i<=n;i++) pl[i]=dis[i];
	sort(pl+1,pl+n+1);
	tot=unique(pl+1,pl+n+1)-pl-1;
	num[tp]=tot;
	for(i=1;i<=n;i++)
	{
		d[tp][i]=lower_bound(pl+1,pl+tot+1,dis[i])-pl;
		h[tp][i]=i;
	}
	sort(h[tp]+1,h[tp]+n+1,cmp);
}
int main()
{
	ll i,j,u,v,w,x,now1,now2,top;
	n=rd();m=rd();
	a=rd();b=rd();
	for(i=1;i<=n;i++) p[i]=rd(),W+=p[i];
	for(i=1;i<=m;i++)
	{
		u=rd();v=rd();w=rd();
		eadd(u,v,w);
	}
	Solve(a,b,0);Solve(b,a,1);
	for(i=1;i<=n;i++)
	{
		if(d[0][h[0][i]]==d[0][h[0][i-1]]) continue;
		x=d[0][h[0][i]];
		memset(del,0,sizeof(del));
		for(j=1;j<i;j++) del[h[0][j]]=1;
		now1=0;now2=0;
		for(j=1;j<=n;j++) if(!del[j]) now1+=p[j],now2++;
		f[x][1]=now1;g[x][1]=now2;
		for(j=2;j<=n;j++)
		{
			if(!del[h[1][j-1]]) del[h[1][j-1]]=1,now1-=p[h[1][j-1]],now2--;
			if(d[1][h[1][j]]!=d[1][h[1][j-1]])
			{
				f[x][d[1][h[1][j]]]=now1;g[x][d[1][h[1][j]]]=now2;
			}
		}
	}
	for(i=num[0];i>=1;i--)
	{
		for(j=num[1],top=num[1]+1;j>=1;j--)
		{
			while(top>j&&g[i][top-1]<g[i][j]) top--;
			pos[i][j][1]=top;
		}
	}
	for(j=num[1];j>=1;j--)
	{
		for(i=num[0],top=num[0]+1;i>=1;i--)
		{
			while(top>i&&g[top-1][j]<g[i][j]) top--;
			pos[i][j][0]=top;
		}
	}
	for(i=num[0];i>=1;i--)
	{
		for(j=num[1];j>=1;j--)
		{
			dp[i][j][0]=f[i][j]-mn[pos[i][j][0]][j][0];
			dp[i][j][1]=f[i][j]-mn[i][pos[i][j][1]][1];
			mn[i][j][0]=min(mn[i+1][j][0],dp[i][j][1]);
			mn[i][j][1]=min(mn[i][j+1][1],dp[i][j][0]);
		}
	}
	if(dp[1][1][0]>W-dp[1][1][0]) puts("Break a heart");
	else if(dp[1][1][0]<W-dp[1][1][0]) puts("Cry");
	else puts("Flowers");
	return 0;
}