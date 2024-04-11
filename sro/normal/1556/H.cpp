#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
ll inline rand(ll L, ll R) { return uniform_int_distribution<ll>(L, R)(Rand); }
double inline frand() { return uniform_real_distribution<double>(0, 1)(Rand); }

struct UnionFind {
	int fa[55];
	void inline init() { memset(fa, -1, sizeof(fa)); }
	UnionFind() {init();}
	int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if (a == b) return 0;
		if (fa[a] < fa[b]) swap(a, b);
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

int N, K;
int d[55];
int w[55][55], deg[55], dg[55];
bool sel[55][55];
vector<tuple<int, int, int> > egs;
vector<pair<int, int> > negs;

int calc() {
	uf.init();
	int res = 0, es = 0;
	egs.clear();
	memset(deg, 0, sizeof(deg));
	repi(i, N) for (int j = i + 1; j <= N; ++j) {
		if (sel[i][j]) {
			if (!uf.conn(i, j)) return Inf;
			res += w[i][j];
			++deg[i]; ++deg[j]; ++es;
		}
		else egs.emplace_back(w[i][j], i, j);
	}
	sort(egs.begin(), egs.end());
	for (auto &e : egs) {
		int w, u, v;
		tie(w, u, v) = e;
		if (deg[u] == d[u] || deg[v] == d[v]) continue;
		if (!uf.conn(u, v)) continue;
		++deg[u]; ++deg[v]; ++es;
		res += w;
	}
	if (es != N - 1) return Inf;
	return res;
}

int main() {
	scanf("%d%d", &N, &K);
	memset(d, -1, sizeof(d));
	repi(i, K) scanf("%d", d + i);
	repi(i, N) for (int j = i + 1; j <= N; ++j) scanf("%d", w[i] + j);
	repi(i, K) for (int j = i + 1; j <= N; ++j) negs.emplace_back(i, j);
	int cur = calc(), bes = cur;
	for (double tmp = 1145.14; tmp >= 1919.8e-10; tmp *= .996007) {
		int u, v;
		while (1) {
			int id = rand(0, SZ(negs) - 1);
			tie(u, v) = negs[id];
			if (u == v) continue;
			if (u > v) swap(u, v);
			if (!sel[u][v] && (dg[u] == d[u] || dg[v] == d[v])) continue;
			break;
		}
		dg[u] -= sel[u][v];
		dg[v] -= sel[u][v];
		sel[u][v] ^= 1;
		dg[u] += sel[u][v];
		dg[v] += sel[u][v];
		int ncur = calc();
		if (exp((cur - ncur) / tmp) > frand()) {
			cur = ncur;
			bes = min(bes, cur);
		}
		else {
			dg[u] -= sel[u][v];
			dg[v] -= sel[u][v];
			sel[u][v] ^= 1;
			dg[u] += sel[u][v];
			dg[v] += sel[u][v];
		}
	}
	printf("%d\n", bes);
	return 0;
}