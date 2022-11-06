//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, m, ans = -1;
vector<int> e[N], rt;
map<int, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N], sz[N];
	void init(int x) {rep(i, 1, x) fa[i] = i, sz[i] = 1;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		fa[u] = v;
		sz[v] += sz[u];
		return 1;
	}
}dsu;

int main() {
	scanf("%d%d", &n, &m);
	dsu.init(n);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(u, 1, n) {
		mp.clear();
		for(auto v : e[u]) ++mp[dsu.find(v)];
		for(auto v : rt) if(mp[dsu.find(v)] < dsu.sz[v] && dsu.merge(u, v));
		if(u == dsu.find(u)) rt.push_back(u);
	}
	rep(i, 1, n) ans += i == dsu.find(i);
	printf("%d\n", ans);
	return 0;
}