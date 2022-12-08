#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;
vector<vector<int>> adj;
int m;
ll k, x;
int vals[100001][3][11]; //0 means lower, 1 means upper, 2 means same
ll recurse(int cur, int type, int level, int par) {
	if (vals[cur][type][level] != -1) {
		return vals[cur][type][level];
	}
	ll numcur;
	int take = level;
	if (type == 0) {
		numcur = k-1;
	}
	else if (type == 1) {
		numcur = 1;
		take--;
		if (take < 0) {
			vals[cur][type][level] = 0LL;
			return 0LL;
		}
	}
	else {
		numcur = m-k;
	}
	ll tv[take+1];
	for (int i = 0; i <= take; i++) {
		tv[i] = 0LL;
	}
	tv[0] = 1LL;
	bool seen = false;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (v == par) continue;

		ll current[take+1];
		for (int j = 0; j <= take; j++) {
			ll temp;
			if (type == 1) {
				temp = recurse(v, 0, j, cur);
			}
			else if (type == 0) {
				temp = (recurse(v, 1, j, cur) + recurse(v, 0, j, cur) + 
					recurse(v, 2, j, cur))%mod;
			}
			else {
				temp = (recurse(v, 0, j, cur) + 
					recurse(v, 2, j, cur))%mod;
			}
			current[j] = temp;
		}
		ll ntv[take+1];
		for (int k = 0; k <= take; k++) {
			ntv[k] = 0LL;
		}
		for (int k = take; k >= 0; k--) {
			for (int j = 0; j<= 10; j++) {
				if (k-j >= 0) ntv[k] = (ntv[k]+tv[k-j]*current[j])%mod;
			}
		}
		for (int k = 0; k <= take; k++) {
			tv[k] = ntv[k];
		}
		seen = true;
	}

	tv[take] = (tv[take]*numcur)%mod;
	vals[cur][type][level] = tv[take];
	// cout << cur << " " << type << " " << level << " cur: " << tv[take] << endl;
	return tv[take];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
		
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> k >> x;
	for (int i = 0; i <= n; i++) {
	
		for (int j = 0; j <= x; j++) {
			vals[i][0][j] = vals[i][1][j] = vals[i][2][j] = -1;
		}
	}
	ll ans = 0LL;
	for (int i = 0; i <= x; i++) {
		ans  = (ans + recurse(1, 0, i, 0) + recurse(1, 1, i, 0) 
			+ recurse(1, 2, i, 0))%mod;
	}
	// ll ans = recurse(1, 0, 0);
	// ans = (ans + recurse(1, 1, 0))%mod;
	// ans = (ans + recurse(1, 2, 0))%mod;
	cout << ans << endl;
	// cin >> ans;

}