#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

const ll INF = (ll)(1e17) + 666;

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll cnt0 = n / 2;
	ll cnt1 = n - cnt0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (x == 0) {
			a[i] = -1;
		} else {
			if (x & 1) {
				--cnt1;
			} else {
				--cnt0;
			}
			a[i] = x & 1;
		}
	}
	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(cnt0 + 2, vector<ll>(cnt1 + 2, INF)));
	dp[0][cnt0][cnt1] = 0;
	dp[1][cnt0][cnt1] = 0;
	for (ll i = 0; i < n; ++i) {
		vector<vector<vector<ll>>> new_dp(2, vector<vector<ll>>(cnt0 + 2, vector<ll>(cnt1 + 2, INF)));
		if (a[i] == -1) {
			for (ll i0 = 0; i0 <= cnt0; ++i0) {
				for (ll i1 = 0; i1 <= cnt1; ++i1) {
					new_dp[0][i0][i1] = min(dp[0][i0 + 1][i1], dp[1][i0 + 1][i1] + 1);
					new_dp[1][i0][i1] = min(dp[0][i0][i1 + 1] + 1, dp[1][i0][i1 + 1]);
				}
			}
		} else {
			ll x = a[i];
			for (ll i0 = 0; i0 <= cnt0; ++i0) {
				for (ll i1 = 0; i1 <= cnt1; ++i1) {
					new_dp[x][i0][i1] = min(dp[x][i0][i1], dp[1 - x][i0][i1] + 1);
				}
			}
		}
		dp.swap(new_dp);
	}
	cout << min(dp[0][0][0], dp[1][0][0]) << endl;
}

int main() {
	start();
	solve();
	return 0;
}