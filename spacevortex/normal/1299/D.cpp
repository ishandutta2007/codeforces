#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define inv(x) power(x,Mod-2)
#define pb push_back
using namespace std;
typedef long long ll;
const ll Mod=1e9+7;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
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
const ll N=1e5+50,E=N<<1,Log=4,P=Log+3,U=400;
ll n,m,cnt=1,ans=0,top=0,num=0;
ll he[N],col[N],del[N],h[P],dis[N],dp[N][U],trs[U][U],hvl[N];
ll pl[U],t[U][P],dy[N],det[N];
struct Edge{ll v,w,nxt;}e[E];
void eadd(ll u,ll v,ll w)
{
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].nxt=he[u];he[u]=cnt;
	cnt++;e[cnt].v=u;e[cnt].w=w;e[cnt].nxt=he[v];he[v]=cnt;
}
void trans(ll s)
{
	ll i;
	for(i=1;i<=num;i++)
	{
		if(trs[i][s]!=-1)
		{
			upd(dp[top+1][trs[i][s]],dp[top][i]);
		}
	}
}
void ins(ll x)
{
	ll i,j;
	for(i=Log;i>=0;i--)
	{
		if((x&(1ll<<i))==0) continue;
		if(h[i]) 
		{
			x^=h[i];continue;
		}
		for(j=i-1;j>=0;j--)
		{
			if((x&(1<<j))&&h[j]) x^=h[j];
		}
		h[i]=x;
		for(j=i+1;j<=Log;j++)
		{
			if(h[j]&(1<<i)) h[j]^=x;
		}
		return ;
	}
	h[5]=1;
}
ll gvl(ll f[P])
{
	ll ret=0,i;
	for(i=Log;i>=0;i--)
	{
		ret=(ret<<(i+1))|f[i];
	}
	return dy[ret];
}

void dfs(ll x,ll nf)
{
	ll i,v,w;
	for(i=he[x];i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;
		if(v==nf||col[v]) continue;
		if(det[v]>0)
		{
			if(det[v]<det[x])
			{
				ins(dis[x]^dis[v]^w);
			}
			continue;
		}
		det[v]=det[x]+1;
		dis[v]=dis[x]^w;
		dfs(v,x);
	}
}
void get(ll rt,ll f[P])
{
	memset(h,0,sizeof(h));
	det[rt]=1;
	col[rt]=0;
	dfs(rt,1);
	col[rt]=1;
	for(ll i=0;i<=5;i++) f[i]=h[i];
}
void solve(ll a)
{
	static ll f[P];
	get(a,f);
	trans(1);
	if(f[5]!=1) trans(gvl(f));
	top++;
}

void solve(ll a,ll b,ll w)
{
	ll i;
	static ll f[P],g[P];
	get(a,f);get(b,g);
	memset(h,0,sizeof(h));
	if(f[5]||g[5]) h[5]=1;
	for(i=0;i<=Log;i++) h[i]=f[i];
	for(i=0;i<=Log;i++) if(g[i]) ins(g[i]);
	trans(1);
	if(h[5]!=1) trans(gvl(h)),trans(gvl(h));
	ins(w^hvl[a]^hvl[b]);
	if(h[5]!=1) trans(gvl(h));
	top++;
}
void srh(ll id,ll w,ll rw)
{
	ll i,x;
	if(id==-1)
	{
		num++;
		pl[num]=rw;
		for(i=0;i<=Log;i++) t[num][i]=h[i];
		dy[rw]=num;
		return ;
	}
	h[id]=0;
	srh(id-1,w,rw<<(id+1));
	if((w&(1<<id))==0)
	{
		for(i=0;i<(1<<id);i++)
		{
			x=i|(1<<id);
			h[id]=x;
			srh(id-1,w|x,(rw<<(id+1))|x);
		}
	}
}
ll mrg(ll a,ll b)
{
	ll i;
	memset(h,0,sizeof(h));
	for(i=0;i<=Log;i++) h[i]=t[a][i];
	for(i=0;i<=Log;i++) if(t[b][i]) ins(t[b][i]);
	if(h[5]) return -1;
	else return gvl(h);
}
int main()
{
	ll i,j,u,v,w,x,y,W;
	n=rd();m=rd();
	col[1]=1;
	for(i=1;i<=m;i++)
	{
		u=rd();v=rd();w=rd();
		if(u==1) col[v]=1,hvl[v]=w;
		if(v==1) col[u]=1,hvl[u]=w;
		eadd(u,v,w);
	}
	srh(4,0,0);
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=num;j++)
		{
			trs[i][j]=mrg(i,j);
		}
	}
	dp[0][1]=1;
	for(x=2;x<=n;x++)
	{
		if(col[x]==0||del[x]==1) continue;
		y=-1;
		for(i=he[x];i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(v!=1&&col[v]==1) 
			{
				y=v;W=w;break;
			}
		}

		if(y==-1)
		{
			del[x]=1;solve(x);
		}
		else
		{
			del[x]=del[y]=1;solve(x,y,W);
		}
	}
	for(i=1;i<=num;i++) upd(ans,dp[top][i]);
	printf("%lld\n",ans);
	return 0;
}