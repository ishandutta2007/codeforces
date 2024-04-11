#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	vector<pll> lines;

	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		k = -k, m = -m;
		lines.push_back({k, m});
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}

	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -l.k * x + -l.m;
	}
} cht[MAXN];

ll ans[MAXN], n, A[MAXN], B[MAXN];
vector<pll> lines[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	if (p && adj[v].size() == 1) {
		cht[v].add(B[v], 0);
		lines[v].push_back({B[v], 0});
		return;
	}

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);

		if (lines[v].size() < lines[u].size()) {
			lines[v].swap(lines[u]);
			cht[v].swap(cht[u]);
		}

		for (pll e : lines[u]) {
			cht[v].add(e.X, e.Y);
			lines[v].push_back(e);
		}
	}

	
	ans[v] = cht[v].query(A[v]);
	cht[v].add(B[v], ans[v]);
	lines[v].push_back({B[v], ans[v]});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << sep;
	cout << endl;
	return 0;
}