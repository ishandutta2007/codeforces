#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 300010;

V<int> g[maxn];
bool vis[maxn];
int par[maxn];

V<pii> cycles;
int dep[maxn];

void dfs(int v, int p, int d) {
	vis[v] = true;
	dep[v] = d;
	par[v] = p;

	for (int to : g[v]) if (to != p) {
		if (vis[to]) { //ancestor
			cycles.eb(minmax(v, to));
		} else {
			dfs(to, v, d + 1);
		}
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);

	rep(i, m) {
		int a, b; scanf("%d %d", &a, &b); --a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	rep(i, n) if (!vis[i]) {
		dfs(i, -1, 0);
	}
	sort(ALL(cycles));
	cycles.erase(unique(ALL(cycles)), cycles.end());

	V<int> tor(n, n + 1); //[i, tor[i]) : ok

	for (auto e : cycles) {
		dump(e);
		int mini = min(e.fi, e.se), maxi = max(e.fi, e.se);
		int p = e.fi, q = e.se;
		if (dep[p] < dep[q]) swap(p, q);
		while (dep[p] > dep[q]) {
			p = par[p];
			chmin(mini, p);
			chmax(maxi, p);
		}
		while (p != q) {
			p = par[p];
			q = par[q];
			chmin(mini, min(p, q));
			chmax(maxi, max(p, q));			
		}
		dump(mp(mini, maxi));
		chmin(tor[mini], maxi);
	}

	for (int i = n - 2; i >= 0; --i) {
		chmin(tor[i], tor[i + 1]);
	}

	int q; scanf("%d", &q);

	V<ll> pref(n + 1);
	rep(i, n) {
		pref[i + 1] = pref[i] + tor[i];
	}

	while (q--) {
		int l, r; scanf("%d %d", &l, &r); --l;
		int p = lower_bound(tor.begin() + l, tor.begin() + r, r) - tor.begin();
		ll ans = (pref[p] - pref[l]) + ll(r) * (r - p) - (ll)(l + r - 1) * (r - l) / 2;
		/*
		for (int i = l; i < p; ++i) {
			ans += tor[i] - i;
		}
		for (int i = p; i < r; ++i) {
			ans += r - i;
		}*/
		printf("%lld\n", ans);
	}

	return 0;
}