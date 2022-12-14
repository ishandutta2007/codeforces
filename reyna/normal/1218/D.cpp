#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
	{
		int r=1;
		while(b)
		{
			if(b&1) r=mult(r,a);
			a=mult(a,a);
			b>>=1;
		}
		return r;
	}
 
map<ii,int> E;
vi adj[121211];
int par[121211];
int bk[121212];
int vis[121212];
const int siz = 131072;
int h[121311];
void dfs(int u, int p)
{
	par[u]=p;vis[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(vis[v])
		{
			if(h[u]<h[v]) bk[v]=u;
		}
		else
		{
			h[v]=h[u]+1;
			dfs(v,u);
		}
	}
}
 
void moddo(int &x) {
    while (x >= MOD) x -= MOD;
        
    if(x<0) x+=MOD;
}
 
int F[45][155555];
int G[45][155555];
 
void fwht(int dim, int *data) 
{
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                data[i + j] = (a + b) % MOD;
                data[i + j + len] = (MOD + a - b) % MOD;
            }   
        }
    }
}
 
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(bk,-1,sizeof(bk));
	int n,m; cin>>n>>m;
	par[0]=-1;
	int totxr=0;
	for(int i=0;i<m;i++)
	{
		int u,v,c; cin>>u>>v>>c; u--; v--; totxr^=c;
		adj[u].pb(v); adj[v].pb(u); E[{u,v}]=E[{v,u}]=c;
	}
	dfs(0,-1);
	vector<vi> cycles;
	for(int i=0;i<n;i++)
	{
		if(bk[i]>=0)
		{
			int tp=bk[i];
			vi cur;
			int x=i;
			cur.pb(E[{i,tp}]);
			//cerr<<"OVERALL: "<<i<<' '<<tp<<'\n';
			while(x!=tp)
			{
				//cerr<<x<<' '<<par[x]<<'\n';
				cur.pb(E[{x,par[x]}]);
				x=par[x];
			}
			cycles.pb(cur);
		}
	}
	if(cycles.empty())
	{
		cout<<totxr<<' '<<1<<'\n'; return 0;
	}
	for(int i=0;i<cycles.size();i++)
	{
		for(int x:cycles[i])
		{
			F[i][x]++; G[i][x]=1;
		}
		fwht(siz,F[i]); fwht(siz,G[i]);
	}
	for(int i=1;i<cycles.size();i++)
	{
		for(int j=0;j<siz;j++)
		{
			moddo(F[i][j]);
			F[0][j]=mult(F[0][j],F[i][j]);
			G[0][j]=mult(G[0][j],G[i][j]);
		}
	}
	fwht(siz,F[0]); fwht(siz,G[0]); int iv=modpow(siz,MOD-2);
	for(int i=0;i<siz;i++)
	{
		F[0][i]=mult(F[0][i],iv);
		G[0][i]=mult(G[0][i],iv);
	}
	int mn=int(1e9);  int cnt=0;
	//should not have answer=0 mod 1e9+7 other than 0 
	for(int i=0;i<siz;i++)
	{
		moddo(F[0][i]);
		if(G[0][i]>0)
		{
			//cerr<<i<<' '<<totxr<<' '<<F[0][i]<<'\n';
			if((i^totxr)<mn)
			{
				mn=(i^totxr); cnt=F[0][i];
			}
		}
	}
	cout<<mn<<' '<<cnt<<'\n';
}