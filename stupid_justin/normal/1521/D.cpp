#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 

int n,ans,idn,id1;
set<int> T[N];
int add1[N],add2[N];
int sz[N],flag[N],Fa[N],fr[N];
void dfs(int u,int fa)
{
	sz[u]=1;fr[u]=u;Fa[u]=fa;
	int son=0;
	for(int v:T[u]) if (v!=fa)
	{
		dfs(v,u);
		sz[u]+=sz[v];
		if (flag[u] && !flag[v]) flag[v]=1,add1[v]=v,add2[v]=fr[v];
		else if(!flag[v])
		{
			++son;
			if (fr[u]!=u) flag[u]=1,add1[u]=fr[u],add2[u]=fr[v];
			else fr[u]=fr[v];
		}
	}
	sz[u]-=son;
	if(u==1 && son<2) flag[1]=1,add1[1]=1,add2[1]=fr[1];
}
void solve()
{
	rd(n);
	for (int i=1;i<=n;i++) T[i].clear(),fr[i]=sz[i]=flag[i]=Fa[i]=add1[i]=add2[i]=0;
	for (int i=1,a,b;i<n;i++) rd(a),rd(b),T[a].insert(b),T[b].insert(a);
	dfs(1,0);
	cout<<sz[1]-1<<"\n";
	int la=0;
	for (int i=1;i<=n;i++) if (flag[i])
	{
		if (!la) la=add2[i];
		else cout<<i<<" "<<Fa[i]<<" "<<la<<" "<<add1[i]<<"\n",la=add2[i];
	}

}
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		solve();
	}
}