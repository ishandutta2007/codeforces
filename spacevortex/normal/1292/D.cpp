#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
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
const ll n=5005,P=5050,N=20050,E=2e5+10;
ll tot,cnt=1,Q,zds,G=-1,ans=0;
ll h[P][P],f[N],dis[N],he[N],siz[N],val[N],vmx[N],bf[N],bel[N],pl[N];
struct Edge
{
	ll v,w,nxt;
}e[E];
void eadd(ll u,ll v,ll w)
{
	//if(w<0) puts("WA");
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].nxt=he[u];he[u]=cnt;
	cnt++;e[cnt].v=u;e[cnt].w=w;e[cnt].nxt=he[v];he[v]=cnt;
}
void dfs(ll x,ll nf)
{
	siz[x]=val[x];
	for(ll i=he[x];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==nf) continue;
		dfs(v,x);
		siz[x]+=siz[v];
		cmax(vmx[x],siz[v]);
	}
	cmax(vmx[x],zds-siz[x]);
	if(G==-1||vmx[x]<vmx[G]) G=x;
}
void dfs2(ll x,ll nf,ll d)
{
	ll i,v,w;
	ans+=d*val[x];
	for(i=he[x];i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;
		if(v==nf) continue;
		dfs2(v,x,d+w);
	}
}
bool cmp(const ll &a,const ll &b){return f[a]>f[b];}
ll getf(ll x)
{
	if(x==bf[x]) return x;
	else return bf[x]=getf(bf[x]);
}
int main()
{
	ll i,j,x,y,xf,yf,num;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++) h[i][j]=h[i-1][j];
		dis[i]=dis[i-1];
		x=i;
		for(j=2;j*j<=x;j++)
		{
			while(x%j==0) dis[i]++,h[i][j]++,x/=j;
		}
		if(x>1) dis[i]++,h[i][x]++;
		num=0;
		for(j=n;j>=1;j--)
		{
			if(h[i][j]>h[i-1][j]) 
			{
				num+=h[i-1][j];break;
			}
			num+=h[i][j];
		}
		f[i]=num;
	}
	for(i=1;i<n;i++) pl[i]=i+1;
	sort(pl+1,pl+n,cmp);
	tot=n;
	for(i=1;i<=n;i++) bf[i]=bel[i]=i;
	for(i=1;i<n;i++)
	{
		x=pl[i]-1;y=pl[i];
		xf=getf(x);yf=getf(y);
		tot++;
		dis[tot]=f[pl[i]];
		eadd(bel[xf],tot,dis[bel[xf]]-dis[tot]);
		eadd(bel[yf],tot,dis[bel[yf]]-dis[tot]);
		bf[yf]=xf;bel[xf]=tot;
	}
	Q=rd();zds=Q;
	while(Q--)
	{
		x=rd();
		if(x==0) x=1;
		val[x]++;
	}
	dfs(1,0);
	dfs2(G,0,0);
	cout<<ans;
	return 0;
}