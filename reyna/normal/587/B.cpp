//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 49;
const int mod = 1e9 + 7;
pair<int, int> p[N];
int a[N], dp[N], sum[N], n, l, k;



int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = {a[i], i};	
	}
	sort(p, p + n);
	int res = 0, ls = 0;
	for (int i = 0; i < n; i++) {
		sum[0]++;
		for (int j = 1; j < k; j++) {
			if (p[i].first != p[i + 1].first) {
				for (int cur = ls; cur <= i; cur++) {
					sum[j] = (sum[j] + sum[j - 1]) % mod;
					int cnt = (l / n) + ((l % n) > p[cur].second) - j;if (cnt >= 0) cnt %= mod;
					if (cnt >= 0)
						res = (res + cnt * sum[j - 1]) % mod;
				}
			}
		}
		if (p[i].first != p[i + 1].first) ls = i + 1;
	}
	cout << (res + l) % mod << endl;
	return 0;
	
	
}