// Codeforces - mycopka

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef int64_t ll;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> a(n + 2);
	for (ll i = 1; i <= n; ++i) {
		a[i] = s[i - 1] - 'a';
	}
	a[0] = a[n + 1] = 28;
	n = n + 2;
	vector<vector<ll>> dp(n, vector<ll>(n));
	for (ll i = 1; i < n; ++i) {
		dp[i - 1][i] = 1;
	}
	for (ll len = 3; len < n; ++len) {
		for (ll begin = 0, end = len - 1; end < n; ++begin, ++end) {
			bool flag = false;
			for (ll i = begin + 1; i < end; ++i) {
				if (a[i] - 1 != a[begin] && a[i] - 1 != a[end]) {
					continue;
				}
				if (dp[begin][i] && dp[i][end]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				dp[begin][end] = 1;
			}
		}
	}
	vector<ll> dp2(n);
	for (ll end = 0; end < n; ++end) {
		for (ll begin = 0; begin < end; ++begin) {
			dp2[end] = max(dp2[end], dp[begin][end] * (end - begin - 1 + dp2[begin]));
		}
	}
	ll result = 0;
	for (ll i : dp2) {
		result = max(result, i);
	}
	cout << result << endl;
	return 0;
}