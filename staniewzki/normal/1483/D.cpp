#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	LL inf = 1e18;
	vector dst(n, vector<LL>(n, inf));
	REP(i, n) dst[i][i] = 0;
	REP(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		dst[u][v] = w;
		dst[v][u] = w;
	}
	auto e = dst;

	REP(k, n) REP(i, n) REP(j, n)
		dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int q;
	cin >> q;
	vector tri(n, vector<LL>(n));
	REP(i, q) {
		int u, v, l;
		cin >> u >> v >> l;
		u--, v--;
		tri[u][v] = l;
	}

	vector pre(n, vector<LL>(n, inf));
	REP(j, n) REP(k, n) REP(x, n)
		pre[j][k] = min(pre[j][k], dst[j][x] - tri[k][x]);

	int ans = 0;
	REP(i, n) REP(j, i) {
		bool found = false;
		REP(s, 2) {
			REP(k, n) {
				if(dst[k][i] + e[i][j] + pre[j][k] <= 0)
					found = true;
			}
			swap(i, j);
		}
		ans += found;
	}

	cout << ans << "\n";
}