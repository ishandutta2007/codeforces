#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair
#define id(i,j) ((i-1)*m+j)

using namespace std;
const int N=300005,mod=998244353;
typedef long long LL;
const LL INF=10000000000000000ll;
bool vis[N];
int n,m;
LL ans,dis[N],p,q;
vector <char> s[N];
char S[N];

const int hx[]={0,0,-1,1};
const int hy[]={1,-1,0,0};

struct edge
{
	int v;
	LL d;
} ;
vector <edge> vt[N];

struct hp
{
	int x;
	LL d;
	
	bool operator < (const hp &t) const
	{
		return d>t.d;
	}
} ;

priority_queue <hp> Q;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,LL d)
{
	if(vis[u] || vis[v]) return;
	vt[u].pb((edge){v,d});
}

void solve()
{
	n=getint(),m=getint();
	p=getint(),q=getint();
	rep(i,1,n*m) vt[i].clear();
	rep(i,1,n)
	{
		s[i].clear();
		s[i].pb(0);
		scanf("%s",S+1);
		rep(j,1,m) s[i].pb(S[j]);
	}
	rep(i,1,n) rep(j,1,m) vis[id(i,j)]=0;
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='#') vis[id(i,j)]=1;
	rep(i,1,n) rep(j,1,m)
	{
		if(s[i][j]=='L')
		{
			if(j+2<=m) addedge(id(i,j+2),id(i,j),q);
			if(j-1>=1) addedge(id(i,j-1),id(i,j+1),q);
			
			if(i-1>=1) addedge(id(i-1,j),id(i,j+1),p);
			if(i-1>=1) addedge(id(i-1,j+1),id(i,j),p);

			if(i+1<=n) addedge(id(i+1,j),id(i,j+1),p);
			if(i+1<=n) addedge(id(i+1,j+1),id(i,j),p);
		}
		if(s[i][j]=='U')
		{
			if(i+2<=n) addedge(id(i+2,j),id(i,j),q);
			if(i-1>=1) addedge(id(i-1,j),id(i+1,j),q);

			if(j-1>=1) addedge(id(i,j-1),id(i+1,j),p);
			if(j-1>=1) addedge(id(i+1,j-1),id(i,j),p);
			
			if(j+1<=m) addedge(id(i,j+1),id(i+1,j),p);
			if(j+1<=m) addedge(id(i+1,j+1),id(i,j),p);
		}
	}
	rep(i,1,n*m) dis[i]=INF;
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='.')
	{
		dis[id(i,j)]=0;
		Q.push((hp){id(i,j),0});
	}
	while(!Q.empty())
	{
		int x=Q.top().x;
		Q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto e:vt[x])
		{
			int v=e.v;
			if(dis[v]>dis[x]+e.d)
			{
				dis[v]=dis[x]+e.d;
				Q.push((hp){v,dis[x]+e.d});
			}
		}
	}

	ans=INF;
	rep(i,1,n) rep(j,1,m)
	{
		rep(k,0,3)
		{
			int x=i+hx[k];
			int y=j+hy[k];
			if(x>=1 && x<=n && y>=1 && y<=m)
				ans=min(ans,dis[id(i,j)]+dis[id(x,y)]);
		}
	}
	if(ans==INF) puts("-1");
	else printf("%lld\n",ans);		
}

int main()
{
	int T=1;
	while(T--) solve();
	return 0;
}