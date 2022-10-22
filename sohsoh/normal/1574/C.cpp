// orz ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

vector<int> v;
int n, sum;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
	}

	sort(all(v));

	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		
		ll ans = ll(8e18);
		auto it = lower_bound(all(v), x);
		if (it != v.end())
			ans = max(0ll, y - (sum - *it));
		if (it != v.begin()) {
			it--;
			ans = min(ans, max(0ll, x - *it + max(0ll, y - (sum - *it))));
		}

		cout << ans << endl;
	} 
	return 0;
}