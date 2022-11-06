//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, k, a[N];
vector<tuple<int, int, int> > e;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N];
	void init(int x) {rep(i, 1, x) fa[i] = i;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		fa[u] = v;
		return 1;
	}
}dsu;
int kruskal() {
	dsu.init(n);
	sort(e.begin(), e.end(), [](auto x, auto y) {
		return get<2>(x) < get<2>(y);
	});
	int ans = 0;
	rep(i, 0, m-1) {
		int u = get<0>(e[i]), v = get<1>(e[i]), w = get<2>(e[i]);
		u = dsu.find(u); v = dsu.find(v);
		if(dsu.merge(u, v)) {
			if(a[u] && a[v]) ans = w;
			a[v] |= a[u];
		}
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, k) {
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e.emplace_back(u, v, w);
	}
	int ans = kruskal();
	rep(i, 1, k) printf("%d%c", ans, " \n"[i==k]);
	return 0;
}