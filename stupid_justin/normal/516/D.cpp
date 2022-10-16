#include<bits/stdc++.h>
#define rd(x) x=read()
#define int long long
#define endl "\n"
#define I inline
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=2e5+5;
int n,q,ans;
struct edge{int v,w;};
vector<edge> T[N];
vector<int> v,p;
void add(int u,int v,int w){T[u].push_back((edge){v,w});T[v].push_back((edge){u,w});}
int dis1[N],dis2[N],dis3[N],f[N],dp[N];
int p1,p2,rt;
void dfs1(int u,int fa,int dis[]) {for (edge e:T[u]) if (e.v!=fa) dis[e.v]=dis[u]+e.w,dfs1(e.v,u,dis);}
void dfs2(int u,int fa,int x)
{
	v.push_back(f[u]); p.push_back(u);
	dp[u]=1;dp[p[lower_bound(v.begin(),v.end(),f[u]-x)-v.begin()-1]]--;
	for(edge e:T[u])
	{
		if(e.v==fa) continue;
		dfs2(e.v,u,x);
		dp[u]+=dp[e.v];
	}
	ans=max(ans,dp[u]);
	v.pop_back();p.pop_back();
}
signed main()
{
	rd(n);
	for (int i=1,u,v,w;i<n;i++) rd(u),rd(v),rd(w),add(u,v,w);
	dfs1(1,0,dis1); for (int i=1;i<=n;i++) if (dis1[i]>dis1[p1]) p1=i;
	dfs1(p1,0,dis2);for (int i=1;i<=n;i++) if (dis2[i]>dis2[p2]) p2=i;
	dfs1(p2,0,dis3);for (int i=1;i<=n;i++) f[i]=max(dis2[i],dis3[i]);
	f[0]=1e12;for (int i=1;i<=n;i++) if (f[i]<f[rt]) rt=i;
	v.push_back(-1e12);p.push_back(0);
	rd(q);
	while (q--)
	{
		int x;rd(x);ans=0;
		dfs2(rt,0,x);cout<<ans<<endl;
	}
}