#include <bits/stdc++.h>

using namespace std;

#define maxn 100010
#define pii pair<int, int>
#define pp pair<int, pii>
#define mp make_pair
int n, m, k;

vector<pii> adj[maxn];

int par[maxn];
int ct[maxn];

int findset(int u) {
	if (par[u] == u) return u;
	return par[u] = findset(par[u]);
}

void unionset(int a, int b) {
	if (rand()%2) {
		ct[b] += ct[a];
		par[a] = b;
	}
	else {
		ct[a] += ct[b];
		par[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) par[i] = i;
	//just print largest edge in mst k times
	int ans = 0;
	int garb;
	for (int i = 0; i < k; i++) {
		cin >> garb;
		ct[garb] = 1;
	}
	int u, v, w;

	vector<pp> ed;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		ed.push_back(mp(w, mp(u, v)));
	}

	sort(ed.begin(), ed.end());
	for (pp cur: ed) {
		u = cur.second.first;
		v = cur.second.second;

		u = findset(u);
		v = findset(v);
		if (u != v) {
			// cout << "UNIONING: " <<  u << " to " << v << endl;
			if (ct[u] > 0 && ct[v] > 0) ans = max(ans, cur.first);
			unionset(u, v);
		}
	}
	for (int i = 0; i < k; i++) {
		cout << ans << " ";
	}
	cout << endl;
}