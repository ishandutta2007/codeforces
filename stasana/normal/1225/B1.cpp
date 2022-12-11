#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

inline void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

inline void solve() {
	ll n, k, d;
	cin >> n >> k >> d;
	vector<ll> used(k);
	vector<ll> a(n);
	ll cnt = 0;
	ll res = 1e9;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		++used[a[i]];
		if (used[a[i]] == 1) {
			++cnt;
		}
		if (i >= d) {
			--used[a[i - d]];
			if (used[a[i - d]] == 0) {
				--cnt;
			}
		}
		if (i >= d - 1) {
			res = min(res, cnt);
		}
	}
	cout << res << endl;
}

int main() {
	start();
	ll n;
	cin >> n;
	while (n) {
		--n;
		solve();
	}
	return 0;
}