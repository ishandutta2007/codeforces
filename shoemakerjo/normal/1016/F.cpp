#include <bits/stdc++.h>

using namespace std;
#define maxn 300010
#define ll long long
#define pil pair<int, ll>
#define pli pair<ll, int>
#define mp make_pair
#define pii pair<int, int>

int n, m;
vector<vector<pil>> adj(maxn);
vector<pli> reinsert(maxn);

set<pii> tog; //together or smth
ll dist[maxn];
ll dist2[maxn];
bool isbad[maxn];
bool isgone[maxn];

void dfs(int u, int p) {
	for (pil nx : adj[u]) {
		if (nx.first == p) continue;
		dist[nx.first] = dist[u] + nx.second;
		dfs(nx.first, u);
	}
}

void dfs2(int u, int p) {
	for (pil nx : adj[u]) {
		if (nx.first == p) continue;
		dist2[nx.first] = dist2[u] + nx.second;
		dfs2(nx.first, u);
	}
}

int main() {
	fill(isbad, isbad+maxn, false);
	fill(isgone, isgone+maxn, false);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n, m;
	cin >> n >> m;
	int v, u;
	ll w;
	for (int i = 0; i < n-1; i++) {
		cin >> v >> u >> w;
		adj[v].push_back(mp(u, w));
		adj[u].push_back(mp(v, w));
		// tog.insert(pii(v, u));
		// tog.insert(pii(u, v));

	}
	dist[1] = 0;
	dfs(1, -1);
	dist2[n] = 0;
	dfs2(n, -1);

	vector<pli> stuff;

	for (int i = 1; i <= n; i++) {
		stuff.push_back(mp(dist[i], i));
	}
	sort(stuff.begin(), stuff.end());

	// set<int> isgone;
	priority_queue<pli> dn;

	for (int i = 1; i <= n; i++) {
		dn.push(mp(dist2[i], i));
	}
	ll bigguy = 0LL;


	ll odist = dist[n];


	for (int i = 0; i < stuff.size(); i++) {
		// isgone.insert(i);
		// isgone[i] = true;
		int cn = stuff[i].second;
		isgone[cn] = true;
		ll cd = stuff[i].first;
		// isgone.insert(cn);
		bool issat = false;
		reinsert.clear();

		for (pil pp : adj[cn]) {
			isbad[pp.first] = true;
		}

		while (!issat) {
			if (dn.size() == 0) break;
			int val = dn.top().second;
			if (isgone[val]) {
				dn.pop();
				continue;
			}
			if (isbad[val]) {
				reinsert.push_back(dn.top());
				dn.pop();
			}
			else {
				issat = true;
			}
		}

		for (pil pp : adj[cn]) {
			isbad[pp.first] = false;
		}

		if (!issat) {
			for (pli cx : reinsert) {
				dn.push(cx);
			}
			continue;
		}
		if (dn.size() == 0) continue;

		bigguy = max(bigguy, cd + dn.top().first);
		for (pli cx : reinsert) {
			dn.push(cx);
		}
		

	}
	// cout << "bigguy: " << bigguy << endl;


	ll x;
	while (m--) {
		cin >> x;
		if (bigguy + x > odist) {
			cout << odist << '\n';;
		}
		else cout << bigguy+x << '\n';
	}
	cout.flush();
	
}