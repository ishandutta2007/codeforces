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

const ll MAXN = 1e6 + 10;

int n, ans[MAXN];
vector<pll> vec, adj[MAXN];
vector<int> X;
bool vis[MAXN], e_vis[MAXN];

inline int ind(int x) {
	return lower_bound(all(X), x) - X.begin() + 1;
}

void euler(int v) {
	while (!adj[v].empty()) {
		int u = adj[v].back().X, ind = adj[v].back().Y;
		adj[v].pop_back();
		if (e_vis[ind]) continue;

		e_vis[ind] = true;
		euler(u);
		ans[ind] = (u > v);	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		v++;
		vec.push_back({u, v});
		X.push_back(u);
		X.push_back(v);
	}

	sort(all(X));
	for (int i = 0; i < n; i++) {
		int u = ind(vec[i].X), v = ind(vec[i].Y);
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	int lst = 0, t = n + 1;
	for (int i = 1; i < MAXN; i++) {
		if (adj[i].size() & 1) {
			if (lst) {
				adj[lst].push_back({i, t});
				adj[i].push_back({lst, t++});
				lst = 0;
			} else lst = i;
		}
	}

	for (int i = 1; i < MAXN; i++)
		if (!vis[i])
			euler(i);

	for (int i = 0; i < n; i++)
		cout << ans[i] << sep;
	cout << endl;
	return 0;
}