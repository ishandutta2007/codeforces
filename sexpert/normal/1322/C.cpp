#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<ll> val(n);
	for(auto &x : val)
		cin >> x;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		adj[r].push_back(l);
	}
	map<vector<int>, ll> su;
	for(int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
		su[adj[i]] += val[i];
	}
	ll res = 0;
	for(auto p : su) {
		if(p.first.empty())
			continue;
		res = __gcd(res, p.second);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}