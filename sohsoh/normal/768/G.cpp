#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define debug_st(x)		cerr << #x << ": "; for (int e : x) cerr << e << sep; cerr << endl;

const ll MAXN = 1e6 + 10;

int n, hv[MAXN], sz[MAXN], ans[MAXN], rt;
vector<int> adj[MAXN];
multiset<int> S[MAXN], P, O;

void dfs1(int v) {
	sz[v] = 1;
	for (int u : adj[v]) {
		dfs1(u);
		sz[v] += sz[u];
		if (sz[u] > sz[hv[v]]) hv[v] = u;
	}

	O.insert(sz[v]);
}

inline void sack_merge(multiset<int>& a, multiset<int>& b) {
	if (b.size() > a.size()) {
		for (int e : a) b.insert(e);
		a.clear();
		a.swap(b);
	} else {
		for (int e : b) a.insert(e);
		b.clear();
	}
}

inline int lb(multiset<int>& st, int x) {
	auto it = st.upper_bound(x);
	if (it == st.begin()) return -2 * n; //
	return *prev(it);
}

void dfs2(int v) {
	O.erase(O.find(sz[v]));
	P.insert(sz[v]);
	set<pll> st;

	if (v != rt) st.insert({n - sz[v], -1});
	for (int u : adj[v]) {
		if (u == hv[v]) continue;
		dfs2(u);
		st.insert({sz[u], u});
		for (int e : S[u]) O.insert(e);
	}
	
	if (hv[v]) {
		dfs2(hv[v]);
		st.insert({sz[hv[v]], hv[v]});
	}

	for (int u : adj[v])
		if (u != hv[v])
			for (int e : S[u])
				O.erase(O.find(e));

	P.erase(P.find(sz[v]));
	if (st.size() == 1) ans[v] = n - 1;
	else {
		
		pll max_p = *st.rbegin(), min_p = *st.begin(), max2_p = *next(st.rbegin()); // rev iterators
		int l = 0, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			int rem = mid - min_p.X;

			if (max_p.X <= mid) {
				r = mid;
				continue;
			} else if (max2_p.X > mid) {
				l = mid + 1;
				continue;
			}


			int f = 0;
			if (max_p.Y < 0) {
				f = max(lb(P, rem + sz[v]) - sz[v], lb(O, rem));
			} else {
				f = lb(S[max_p.Y], rem);
			}

			if (max_p.X - f > mid) l = mid + 1;
			else r = mid;
		}

		ans[v] = l;
		for (int u : adj[v])
			sack_merge(S[v], S[u]);
	}

	S[v].insert(sz[v]);	
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n == 1) return cout << 0 << endl, 0;

	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		if (u == 0) rt = v;
		else adj[u].push_back(v);
	}

	dfs1(rt);
	dfs2(rt);

	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}