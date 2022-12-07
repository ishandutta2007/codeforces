#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+50,E=N<<1;
ll n,Q,cnt=1,pos,X,Y,D,ans;
ll he[N],dis[N],f[N],p[N],fa[N],val[N],rk[N];
struct Edge{ll v,w,nxt;}e[E];
void eadd(ll u,ll v,ll w)
{
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].nxt=he[u];he[u]=cnt;
}
void dfs(ll x,ll nf)
{
	ll i,v,w;
	if(dis[x]>dis[pos]) pos=x;
	for(i=he[x];i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;
		if(v==nf) continue;
		dis[v]=dis[x]+w;
		dfs(v,x);
	}
}
bool cmp(const ll &a,const ll &b){return f[a]>f[b];}
ll getft(ll x)
{
	if(x==fa[x]) return x;
	else return fa[x]=getft(fa[x]);
}
void link(ll a,ll b)
{
	ll af,bf;
	af=getft(a);bf=getft(b);
	fa[af]=bf;val[bf]+=val[af];
	ans=max(ans,val[bf]);
}
void Solve()
{
	ll i,x,l,r;
	ans=1;
	cin>>D;
	for(i=1;i<=n;i++) fa[i]=i,val[i]=1;
	for(l=1,r=0;l<=n;l++)
	{
		while(r<n&&f[p[l]]-f[p[r+1]]<=D) 
		{
			r++;x=p[r];
			for(i=he[x];i;i=e[i].nxt)
			{
				if(rk[e[i].v]<rk[x]) link(x,e[i].v);
			}
		}
		//printf("U%lld %lld %lld %lld %lld\n",l,r,f[p[l]],f[p[r+1]],D);
		val[getft(p[l])]--;
	}
	printf("%lld\n",ans);
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,u,v,w;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		eadd(u,v,w);eadd(v,u,w);
	}
	pos=0;
	dis[1]=0;dfs(1,0);
	X=pos;

	pos=0;
	dis[X]=0;dfs(X,0);
	for(i=1;i<=n;i++) f[i]=dis[i];
	Y=pos;

	pos=0;
	dis[Y]=0;dfs(Y,0);
	for(i=1;i<=n;i++) f[i]=max(f[i],dis[i]);
	//for(i=1;i<=n;i++) printf("#%lld %lld\n",i,f[i]);
	for(i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++) rk[p[i]]=i;
	cin>>Q;
	while(Q--) Solve();
	return 0;
}