#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
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
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
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

const int MX = 300005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Union find
struct uf{
	vector<int> d;
	uf(){}
	uf(int sz):d(sz,-1){}
	int root(int x){
		if(d[x] < 0) return x;
		return d[x] = root(d[x]);
	}
	void unite(int x, int y){
		x = root(x); y = root(y);
		if(x == y) return;
		if(d[x] > d[y]) swap(x,y);
		if(d[x] == d[y]) d[x]--;
		d[y] = x;
	}
} t;
//

vi to[MX];
P l1[MX], l2[MX];
bool used[MX];

int root;
int dfs(int v, int p=-1) {
	used[v] = true;
	t.unite(v,root);
	l1[v] = P(0,-1);
	l2[v] = P(0,-1);
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		P x = P(dfs(u,v)+1,u);
		l2[v] = max(l2[v],x);
		if (l1[v] < l2[v]) swap(l1[v], l2[v]);
	}
	return l1[v].fi;
}
P best[MX];
void rfs(int v, int a=0, int p=-1) {
	{
		P x(a,p);
		l2[v] = max(l2[v],x);
		if (l1[v] < l2[v]) swap(l1[v], l2[v]);
	}
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		int x = 0;
		if (l1[v].se == u) x = l2[v].fi;
		else x = l1[v].fi;
		rfs(u,x+1,v);
	}
	best[root] = min(best[root],P(l1[v].fi,l2[v].fi));
}

int main(){
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,m) {
		int a, b;
		scanf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	t = uf(n+1);
	rrep(i,n) {
		if (used[i]) continue;
		root = i;
		dfs(i);
		root = t.root(i);
		best[root] = P(INF,INF);
		rfs(i);
	}
	rep(qi,q) {
		int ty, v;
		scanf("%d%d",&ty,&v);
		if (ty == 1) {
			int p = t.root(v);
			printf("%d\n",best[p].fi+best[p].se);
		} else {
			int u;
			scanf("%d",&u);
			int pv = t.root(v);
			int pu = t.root(u);
			if (pv == pu) continue;
			t.unite(pv,pu);
			int p = t.root(pv);
			if (best[pv].fi < best[pu].fi) swap(pv,pu);
			best[pv].se = max(best[pv].se,best[pu].fi+1);
			if (best[pv].fi < best[pv].se) swap(best[pv].fi, best[pv].se);
			best[p] = best[pv];
		}
	}
	
	return 0;
}