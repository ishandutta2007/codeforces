#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int N=4e5+5;
const int M=3e11+5;
const int SZ=550;
const double eps=1e-9;
const int inf=1e11+5;
const int mod=998244853;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,idx,a,b,c,d,x,y,g;
struct edge{int v,id;};
int U[N],V[N];
vector<edge> G[N];
vector<pii> ans;
map<pii,int> Map;
int use[N],vis[N];
vector<int> tmp;
void dfs(int u,int fa,int id)
{
	vis[u]=1;
	for (edge e:G[u]) if (!vis[e.v]) dfs(e.v,u,e.id);
	tmp.clear();
	for (edge e:G[u]) if (e.v!=fa && !use[e.id]) tmp.push_back(e.id);if (id) tmp.push_back(id);
	int sz=tmp.size();
	for (int i=0;i<sz/2*2-1;i+=2) ans.push_back(mp(tmp[i],tmp[i+1])),use[tmp[i]]=use[tmp[i+1]]=1;
}
signed main()
{
    rd(n);
	for (int i=1,u,v;i<=n;i++)
	{
		rd(a);rd(b);rd(c);rd(d);
		x=a*d+b*d,y=b*c,g=__gcd(x,y);x/=g;y/=g;
		if (!Map[mp(x,y)]) Map[mp(x,y)]=++idx;u=Map[mp(x,y)];
		x=a*d,y=b*c+b*d,g=__gcd(x,y);x/=g;y/=g;
		if (!Map[mp(x,y)]) Map[mp(x,y)]=++idx;v=Map[mp(x,y)];
		G[u].push_back((edge){v,i});G[v].push_back((edge){u,i});
		U[i]=u;V[i]=v;
	}
	for (int i=1;i<=idx;i++) if (!vis[i]) dfs(i,0,0);
	cout<<ans.size()<<endl;
	for (pii p:ans) cout<<p.fi<<" "<<p.se<<"\n";
}
/*
*/