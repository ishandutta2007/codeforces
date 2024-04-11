#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 2005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int n, d[MX][MX];
vi to[MX], co[MX];

inline void add(int v, int u, int c) {
	if (c <= 0) return;
	to[v].pb(u); co[v].pb(c);
	to[u].pb(v); co[u].pb(c);
}
void dfs(vi& vs){
	if (sz(vs) == 1) return;
	int v = vs[0];
	vector<vi> g;
	for(int i = 1; i < sz(vs); ++i) {
		int u = vs[i];
		bool join = false;
		rep(j,sz(g)) {
			if (d[v][g[j][0]]+d[v][u]!=d[g[j][0]][u]) {
				g[j].pb(u); join = true;
				break;
			}
		}
		if (!join) g.pb(vi(1,u));
	}
	rep(i,sz(g)) {
		dfs(g[i]);
		int u = g[i][0];
		rep(j,sz(g[i])) if (d[v][u] > d[v][g[i][j]]) u = g[i][j];
		add(v,u,d[v][u]);
	}
}
int f[MX][MX], r;
void cfs(int v, int nd=0, int p=-1){
	if (nd > INF) return;
	f[r][v] = nd;
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		cfs(u,nd+co[v][i],v);
	}
}
bool check() {
	rep(i,n)rep(j,n) f[i][j] = INF;
	rep(i,n){ r = i; cfs(i);}
	rep(i,n)rep(j,n) if (d[i][j] != f[i][j]) return false;
	return true;
}

int main(){
	scanf("%d",&n);
	rep(i,n)rep(j,n) scanf("%d",&d[i][j]);
	vi vs;
	rep(i,n) vs.pb(i);
	dfs(vs);
	puts(check()?"YES":"NO");
	
	return 0;
}