//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m1, m2;
vector<int> ans, v[2];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct DSU {
	int fa[N];
	void init(int x) {rep(i, 1, x) fa[i] = i;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {fa[find(x)] = find(y);}
	bool same(int x, int y) {return find(x) == find(y);}
}a[2];

int main() {
	scanf("%d%d%d", &n, &m1, &m2);
	a[0].init(n); a[1].init(n);
	rep(i, 1, m1) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[0].merge(u, v);
	}
	rep(i, 1, m2) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[1].merge(u, v);
	}
	rep(i, 1, n) {
		if(!a[0].same(1, i) && !a[1].same(1, i)) {
			ans.push_back(i);
			a[0].merge(1, i); a[1].merge(1, i);
		}
	}
	rep(j, 0, 1) rep(i, 1, n) {
		if(!a[j].same(1, i)) {
			v[j].push_back(i);
			a[j].merge(1, i);
		}
	}
	int sz = ans.size(), ext = min(v[0].size(), v[1].size());
	printf("%d\n", sz+ext);
	rep(i, 0, sz-1) printf("1 %d\n", ans[i]);
	rep(i, 0, ext-1) printf("%d %d\n", v[0][i], v[1][i]);
	return 0;
}