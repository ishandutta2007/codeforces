//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
#define int long long
typedef long long ll;
const int N = 1e6+5;

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Edge {
	int u, v, w;
	Edge(int a=0, int b=0, int c=0) : u(a), v(b), w(c) {}
	~Edge() {}
}e[N+N];
int fa[N], sz[N];
void init(int x) {rep(i, 1, x) fa[i] = i, sz[i] = 1;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(Edge a, ll& ans) {
	int u = find(a.u), v = find(a.v), w = a.w;
	if(sz[u] < sz[v]) swap(u, v);
	ans += 1LL * w * sz[u] * sz[v];
	sz[u] += sz[v]; sz[v] = 0;
	fa[v] = u;
}

signed main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n-1) scanf("%lld%lld", &e[i].u, &e[i].v);
	init(n);
	rep(i, 1, n-1) e[i].w = max(a[e[i].u], a[e[i].v]);
	sort(e+1, e+n, [](const Edge& a, const Edge& b) {
		return a.w < b.w;
	});
	ll pos = 0, neg = 0;
	rep(i, 1, n-1) merge(e[i], pos);
	init(n);
	rep(i, 1, n-1) e[i].w = min(a[e[i].u], a[e[i].v]);
	sort(e+1, e+n, [](const Edge& a, const Edge& b) {
		return a.w > b.w;
	});
	rep(i, 1, n-1) merge(e[i], neg);
	printf("%lld\n", pos-neg);
	return 0;
}