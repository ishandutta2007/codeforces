#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second

const int MAXN = 1e6 + 10;

int n, m, ord[MAXN], ans[MAXN], rem[MAXN];
vector<int> adj[MAXN], adj_r[MAXN], st;
bool vis[MAXN];

template<typename T, typename C>
inline void add(pair<T, T>& a, T b, C comp) {
	if (comp(b, a.X)) {
		a.Y = a.X;
		a.X = b;
	} else if (comp(b, a.Y)) a.Y = b;
}

void dfs(int v) {
	vis[v] = true;
	for (int u : adj[v])
		if (!vis[u])
			dfs(u);

	st.push_back(v);
}

inline void majik() {	
	pair<pll, pll> f = {{0, 0}, {0, 0}};
	memset(rem, 0, sizeof rem);

	for (int i = 1; i <= n; i++) {
		int v = st[i];

		if (f.Y.X > i) ans[v] += 2;
		else if (f.X.X > i) ans[v] += (rem[f.X.Y] > i ? 2 : 1);

		pll t = {MAXN - 1, MAXN - 1};
		for (int u : adj[v])
			add(t, ord[u], less<int>());

		add(f, {t.X, i}, greater<pll>());
		rem[t.X] = max(rem[t.X], t.Y);
	}	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_r[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	st.push_back(0);
	reverse(all(st));
	for (int i = 1; i <= n; i++)
		ord[st[i]] = i;

	majik();
	swap(adj, adj_r);
	reverse(st.begin() + 1, st.end());
	for (int i = 1; i <= n; i++)
		ord[st[i]] = i;

	majik();
	cout << count(ans + 1, ans + n + 1, 1) + count(ans + 1, ans + n + 1, 0) << endl;
	return 0;
}