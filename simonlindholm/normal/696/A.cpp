#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

ll lca(ll a, ll b) {
	set<ll> seen;
	while (a != 1) {
		seen.insert(a);
		a /= 2;
	}
	seen.insert(1);
	while (!seen.count(b)) {
		b /= 2;
	}
	return b;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	map<ll, ll> parCosts;
	rep(i,0,N) {
		int t;
		cin >> t;
		if (t == 1) {
			ll v, u, w;
			cin >> v >> u >> w;
			ll l = lca(v, u);
			while (v != l) {
				parCosts[v] += w;
				v /= 2;
			}
			while (u != l) {
				parCosts[u] += w;
				u /= 2;
			}
		}
		else {
			ll v, u;
			ll cost = 0;
			cin >> v >> u;
			ll l = lca(v, u);
			while (v != l) {
				cost += parCosts[v];
				v /= 2;
			}
			while (u != l) {
				cost += parCosts[u];
				u /= 2;
			}
			cout << cost << endl;
		}
	}
	exit(0);
}