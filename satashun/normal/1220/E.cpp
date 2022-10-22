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

template<class T, class U> bool chmax(T& t, const U& u) { if (t < u) { t = u; return 1; } return 0; }
template<class T, class U> bool chmin(T& t, const U& u) { if (t > u) { t = u; return 1; } return 0; }

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

struct LowLink {
	VV<int> g, gg;
	V<int> ord, low, cmp;
	V<bool> vis;
	vector<pair<int, int> > bridge;
	vector<int> articulation;

	void init(int n) {
		g.resize(n); gg.resize(n);
		ord.resize(n);
		low.resize(n);
		vis.resize(n);
		cmp = V<int>(n, -1);
	}

	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void dfs(int v, int p, int &k) {
		vis[v] = true;

		ord[v] = k++;
		low[v] = ord[v];

		bool isArticulation = false;
		int ct = 0;

		for (int to : g[v]) {
			if (!vis[to]) {
				ct++;
				dfs(to, v, k);
				low[v] = min(low[v], low[to]);
				if (~p && ord[v] <= low[to]) isArticulation = true;
				if (ord[v] < low[to]) bridge.push_back(minmax(v, to));
			} else if (to != p) {
				low[v] = min(low[v], ord[to]);
			}
		}

		if (p == -1 && ct > 1) isArticulation = true;
		if (isArticulation) articulation.push_back(v);
	}

	void DFS(int v, int p, int &k) {
		if (p != -1 && ord[p] >= low[v]) {
			cmp[v] = cmp[p];
		} else {
			cmp[v] = k++;
		}

		for (int to : g[v]) {
			if (cmp[to] == -1) {
				DFS(to, v, k);
			}
		}
	}

	void build(int n) {
		{
			int now = 0;
			dfs(0, -1, now);
		}
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (cmp[i] == -1) {
				DFS(i, -1, k);
			}
		}
		for (auto &e : bridge) {
			int u = cmp[e.fi], v = cmp[e.se];
			gg[u].push_back(v); gg[v].push_back(u);
		}
	}
};

const int maxn = 200010;
V<int> g[maxn];
int w[maxn];
int num[maxn];
bool use[maxn];
LowLink L;

bool precalc(int v, int p) {
	bool ok = 0;
	if (num[v] >= 2) {
		ok = 1;
	}
	for (int to : L.gg[v]) {
		if (to != p) {
			if (precalc(to, v)) {
				ok = 1;
			}
		}
	}
	if (ok) {
		use[v] = 1;
	}
	return ok;
}

ll tr;

ll dfs(int v) {
	ll mx = 0;
	use[L.cmp[v]] = 1;

	for (int to : g[v]) if (!use[L.cmp[to]]) {
		auto res = dfs(to);
		chmax(mx, res);
		chmax(tr, res);
	}
	mx += w[v];
	return mx;
}

int main() {
	int n, m; cin >> n >> m;
	rep(i, n) cin >> w[i];

	L.init(n);

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b); g[b].pb(a);
		L.add_edge(a, b);
	}
	int s; cin >> s; --s;

	L.build(n);

	rep(i, n) num[L.cmp[i]]++;
	precalc(L.cmp[s], -1);
	use[L.cmp[s]] = 1;
	ll ans = 0;

	rep(i, n) {
		dump(mp(mp(i, L.cmp[i]),use[L.cmp[i]]));
		if (use[L.cmp[i]]) {
			ans += w[i];
		}
	}

	rep(i, n) {
		if (use[L.cmp[i]]) {
			dfs(i);
		}
	}
	dump(ans);

	cout << ans + tr << endl;

	return 0;
}