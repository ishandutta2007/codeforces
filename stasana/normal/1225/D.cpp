#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int ll;

inline void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

inline void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	map<vector<pair<ll, ll>>, ll> cnt;
	int64_t result = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		vector<pair<ll, ll>> b;
		ll x = a[i];
		for (ll i = 2; i * i <= x; ++i) {
			ll cnt_ = 0;
			while (x % i == 0) {
				x /= i;
				++cnt_;
			}
			cnt_ %= k;
			if (cnt_) {
				b.emplace_back(cnt_, i);
			}
		}
		if (x != 1) {
			b.emplace_back(1, x);
		}
		vector<pair<ll, ll>> need;
		for (auto i : b) {
			need.emplace_back(k - i.first, i.second);
		}
		result += cnt[need];
		cnt[b] += 1;
	}
	cout << result << endl;
}

int main() {
	start();
	solve();
	return 0;
}