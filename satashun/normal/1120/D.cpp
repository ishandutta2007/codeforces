#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
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

class unionfind {
	vector<int> par, rank;

public:
	void init(int n) {
		par.resize(n);
		rank.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;

		if (rank[x] < rank[y]) par[x] = y;
		else {
			par[y] = x;
			if (rank[x] == rank[y]) ++rank[x];
		}
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
} uf;

const int maxn = 200010;

V<int> g[maxn];
V<int> leaf;

pii rng[maxn];

void dfs(int v, int p, int &k) {
	if (g[v].size() == 1 && p != -1) {
		leaf.pb(k);
	}
	int st = k;
	++k;
	for (int to : g[v]) if (to != p) {
		dfs(to, v, k);
	}
	int en = k;
	dump(mp(st, en));

	rng[v] = mp(st, en);
}

int main() {
	int n; cin >> n;
	V<int> c(n);
	rep(i, n) cin >> c[i];

	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}

	{
		int now = 0;
		dfs(0, -1, now);
	}

	V<pair<pii, pii>> edges;
	rep(i, n) {
		int l = lower_bound(ALL(leaf), rng[i].fi) - leaf.begin();
		int r = lower_bound(ALL(leaf), rng[i].se) - leaf.begin();
		dump(mp(l,r));
		edges.eb(mp(c[i], i), mp(l, r));
	}
	sort(ALL(edges));

	ll s = 0;
	V<int> ans;

	uf.init(n);

	for (int i = 0; i < edges.size(); ++i) {
		if (i == 0 || edges[i-1].fi.fi != edges[i].fi.fi) {
			for (int j = i; j < edges.size(); ++j) {
				if (edges[j].fi.fi != edges[i].fi.fi) break;
				auto e = edges[j];

				int w, id;
				tie(w, id) = e.fi;
				int u, v;
				tie(u, v) = e.se;
				if (!uf.same(u, v)) {
					ans.pb(id);
				}
			}
			for (int j = i; j < edges.size(); ++j) {
				if (edges[j].fi.fi != edges[i].fi.fi) break;
				auto e = edges[j];

				int w, id;
				tie(w, id) = e.fi;
				int u, v;
				tie(u, v) = e.se;
				if (!uf.same(u, v)) {
					uf.unite(u, v);
					s += w;
				}
			}			
		}
	}

	sort(ALL(ans));
	cout << s << " " << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] + 1 << " ";
	cout << endl;

	return 0;
}