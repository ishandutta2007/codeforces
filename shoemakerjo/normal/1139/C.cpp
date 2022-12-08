#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
using ll = long long;

int n;
const int maxn = 100010;
int k;
const int maxk = 102;
const int mod = 1000000007;

ll dpold[maxn][2];
ll dpnew[maxn][2];

vector<pii> adj[maxn];

void add(ll & a, ll b) {
	a = (a + b)%mod;
}

ll mult(ll a, ll b) {
	return (a*b)%mod;
}

vector<int> comps[maxn];

int par[maxn];

int findset(int u) {
	if (par[u] == u) return u;
	return par[u] = findset(par[u]);
}

void unionset(int u, int v) {
	u = findset(u);
	v = findset(v);

	par[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	// int u, v, w;

	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < n-1; i++) {
		int u,  v, w;
		cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));

		if (w == 0 && findset(u) != findset(v)) unionset(u, v);
	}

	for (int i = 1; i <= n; i++) {
		comps[findset(i)].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		dpnew[i][0] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dpold[j][0] = dpnew[j][0];
			dpold[j][1] = dpnew[j][1];

			dpnew[j][0] = 0;
			dpnew[j][1] = 0;
		}

		ll tot = 0LL, tot1 = 0LL;
		for (int j = 1; j <= n; j++) {
			add(tot, dpold[j][0]);
			add(tot1, dpold[j][1]);
		}

		for (int j = 1; j <= n; j++) {
			if (comps[j].size() == 0) continue;

			ll csum = 0LL;
			for (int v : comps[j]) {
				add(csum, dpold[v][0]);
			}

			for (int v : comps[j]) {
				add(dpnew[v][0], csum);
				add(dpnew[v][1], tot-csum+mod);
				add(dpnew[v][1], tot1);
			}

		}

	}

	ll res = 0LL;

	for (int j = 1; j <= n; j++) {
		add(res, dpnew[j][1]);
	}
	cout << res << endl;
}