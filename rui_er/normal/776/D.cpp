//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, r[N], key[N][2];
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

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &r[i]);
	rep(i, 1, m) {
		int T;
		for(scanf("%d", &T);T;T--) {
			int x;
			scanf("%d", &x);
			if(key[x][0]) key[x][1] = i;
			else key[x][0] = i;
		}
	}
	dsu.init(m<<1);
	rep(i, 1, n) {
		int a = key[i][0], b = key[i][1];
		dsu.merge(a, b+m*!r[i]);
		dsu.merge(a+m, b+m*r[i]);
	}
	rep(i, 1, m) {
		if(dsu.find(i) == dsu.find(i+m)) {
			return puts("NO")&0;
		}
	}
	puts("YES");
	return 0;
}