#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int Q;
int n,a,b,da,db;
vector<int> T[N];
void add(int u,int v){T[u].push_back(v);T[v].push_back(u);}
int disa[N],dis1[N];
void dfs(int u,int fa,int dis[])
{
	for (int i=0;i<T[u].size();i++)
	{
		int v=T[u][i];
		if (v==fa) continue;
		dis[v]=dis[u]+1;
		dfs(v,u,dis);
	}
}
signed main()
{
	rd(Q);
	while (Q--)
	{
		rd(n);rd(a);rd(b);rd(da);rd(db);
		for (int i=1;i<=n;i++) T[i].clear();
		for (int i=1;i<n;i++)  {int u,v;rd(u);rd(v);add(u,v);}
		if (2*da>=db) {puts("Alice");continue;}
		disa[a]=0;
		dfs(a,0,disa);
		if (disa[b]<=da) {puts("Alice");continue;}
		int id=0;
		for (int i=1;i<=n;i++) if (disa[i]>disa[id]) id=i; 
		dis1[id]=0;
		dfs(id,0,dis1);
		int maxn=0;
		for (int i=1;i<=n;i++) maxn=max(maxn,dis1[i]);
		if (da*2>=maxn) {puts("Alice");continue;}
		puts("Bob");
	}
}