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

inline void solve() {
	vector<pll> vec;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		ll ps = 0, pss = 0;
		for (int i = 1; i <= m; i++) {
			ll x;
			cin >> x;
			ps += x;
			pss += ps;
		}

		vec.push_back({pss, i});
	}

	sort(all(vec));
	cout << vec.front().Y << sep << vec[1].X - vec[0].X << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}