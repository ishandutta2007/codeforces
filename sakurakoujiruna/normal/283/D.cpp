#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e3 + 11;
using ll = long long;

ll a[N];
int cnt[N];
int dp[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	a[n + 1] = 1;
	for(int i = 1; i <= n + 1; i ++) {
		ll t = a[i];
		while(t % 2 == 0) {
			t /= 2;
			cnt[i] ++;
		}
	}
	auto check = [](ll x, ll y) {
		if(y & 1)
			return x % y == 0;
		else
			return (x - y / 2) % y == 0;
	};
	dp[1] = 0;
	for(int i = 2; i <= n + 1; i ++) {
		dp[i] = i - 1;
		if(check(a[i - 1], a[i]))
			dp[i] = min(dp[i - 1], dp[i]);
		for(int j = 1; j + 1 < i; j ++) {
			if(i - j - 1 >= cnt[i]) {
				if(a[j] % (a[i] >> cnt[i]) == 0)
					dp[i] = min(dp[i], dp[j] + i - j - 1);
			} else {
				if(a[j] % (a[i] >> (i - j)) == 0 &&
					a[j] / (a[i] >> (i - j)) % 2 == 1)
					dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
		}
	}
	cout << dp[n + 1] << '\n';
	return 0;
}