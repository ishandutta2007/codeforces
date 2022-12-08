#include <bits/stdc++.h>

using namespace std;

long long c[5005][5005];
const int mod = 998244353;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	c[0][0] = 1;
	for (int i = 1; i < 5005; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v;
	v.push_back(-1);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') v.push_back(i);
	}
	int cnt = v.size() - 1;
	if (k == 0 || k > cnt) {
		cout << 1 << '\n';
		return 0;
	}
	v.push_back(n);
	long long ans = c[v[k + 1] - v[0] - 1][k];
	for (int i = 2; i <= cnt - k + 1; ++i) {
		ans += c[v[i + k] - v[i - 1] - 1][k] - c[v[i + k - 1] - v[i - 1] - 1][k - 1];
	}
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
	return 0;
}