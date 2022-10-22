// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll SQ = 320;

int n, m, k, ans[MAXN], cmp[MAXN], ind;
vector<int> adj[MAXN];
vector<pll> edges[MAXN], A, Q;

void dfs(int v) {
	cmp[v] = ind;
	for (int u : adj[v])
		if (!cmp[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges[c].push_back({u, v});
	}

	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		Q.push_back({u, v});
	}

	for (int i = 1; i <= m; i++) {
		vector<int> V;
		for (pll e : edges[i]) {
			adj[e.X].push_back(e.Y);
		       	adj[e.Y].push_back(e.X);
			V.push_back(e.X);
			V.push_back(e.Y);
		}

		sort(all(V));
		V.resize(unique(all(V)) - V.begin());

		for (int v : V) 
			if (!cmp[v])
				ind++, dfs(v);

		if (V.size() < SQ) {
			for (int v1 : V)
				for (int v2 : V)
					if (cmp[v1] == cmp[v2])
						A.push_back({v1, v2});
		} else {
			for (int i = 0; i < q; i++) {
				pll e = Q[i];
				if (cmp[e.X] != 0 && cmp[e.X] == cmp[e.Y])
					ans[i]++;
			}
		}

		for (int v : V)
			adj[v].clear(), cmp[v] = 0;
	}

	sort(all(A)); //
	for (int i = 0; i < q; i++) {
		pll e = Q[i];
		auto it = lower_bound(all(A), e);
	       	if (it == A.end() || *it != e) {
			cout << ans[i] << endl;
			continue;
		}

		ans[i] -= it - A.begin();
		ans[i] += lower_bound(all(A), make_pair(e.X, e.Y + 1)) - A.begin();	
		cout << ans[i] << endl;
	}
	return 0;
}