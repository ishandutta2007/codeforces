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

int n, sub[MAXN], fen[MAXN], w_lim, l_lim;
bool B[MAXN];
vector<pll> adj[MAXN], vec, tot_vec;
vector<int> Q[MAXN];

inline void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind) 
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

int sub_dfs(int v, int p) {
	sub[v] = 1;
	for (pll e : adj[v]) {
		int u = e.X;
		if (!B[u] && u != p)
			sub[v] += sub_dfs(u, v);
	}

	return sub[v];
}

int centroid(int v, int p, int n) {
	for (pll e : adj[v]) {
		int u = e.X;
		if (u != p && !B[u] && sub[u] * 2 > n)
			return centroid(u, v, n);
	}
	return v;
}

void dfs(int v, int p, int len, ll pw) {
	vec.push_back({pw, len});
	tot_vec.push_back({pw, len});

	for (pll e : adj[v]) {
		int u = e.X, w = e.Y;
		if (u != p && !B[u])
			dfs(u, v, len + 1, w + pw);
	}
}

inline ll calc(vector<pll>& vec) {
	ll ans = 0;
	sort(all(vec));
	for (int i = 0; i < (int) vec.size(); i++) {
		auto it = lower_bound(all(vec), make_pair(w_lim - vec[i].X + 1, -1ll));
		if (it != vec.begin()) Q[it - vec.begin() - 1].push_back(l_lim - vec[i].Y);
	}

	for (int i = 0; i < (int) vec.size(); i++) {
		update(vec[i].Y, 1);
		for (int e : Q[i])
			ans += query(e);

		Q[i].clear();
	}

	for (pll e : vec)
		update(e.Y, -1);

	vec.clear();
	return ans;
}

ll solve(int v) {
	ll ans = 0;
	v = centroid(v, 0, sub_dfs(v, 0));

	B[v] = true;
	tot_vec.push_back({0, 0});
	ans--;

	for (pll e : adj[v]) {
		int u = e.X, w = e.Y;
		if (B[u]) continue;

		dfs(u, v, 1, w);
		ans -= calc(vec);
	}

	ans += calc(tot_vec);

	for (pll e : adj[v])
		if (!B[e.X])
			ans += solve(e.X);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l_lim >> w_lim;
	for (int i = 2; i <= n; i++) {
		int p, w;
		cin >> p >> w;
		adj[p].push_back({i, w});
		adj[i].push_back({p, w});
	}

	cout << solve(1) / 2 << endl;
	return 0;
}