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

inline int solve() {
	int n, k;
	cin >> n >> k;
	vector<int> vec;

	ll s = 0, ans = 0, cnt = n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		s += x;
	}
	
	vec.push_back(0);
	sort(all(vec));

	ll d = 0;
	while (cnt > 0) {
		if (s > k) {
			s -= vec[cnt--] + d;
			continue;
		}

		ll t = (k - s + 1 + cnt - 1) / cnt;

		ans += t * cnt;
		d += t;

		s += cnt * t;
		s -= vec[cnt--] + d;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}