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
const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<pll> vec;
		int n, m, k, q;
		cin >> n >> m >> k >> q;
		ll ans = 1;
		while (q--) {
			int x, y;
			cin >> x >> y;
			vec.push_back({x, y});
		}

		set<int> st_r, st_c;
		reverse(all(vec));
		for (pll e : vec) {
			if (st_r.find(e.X) != st_r.end() && st_c.find(e.Y) != st_c.end()) continue;
			if (int(st_r.size()) == n || int(st_c.size()) == m) break;

			ans = ans * k % MOD;
			st_r.insert(e.X);
			st_c.insert(e.Y);
		}

		cout << ans << endl;
	}
	return 0;
}