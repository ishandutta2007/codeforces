#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL mod = 998244353;
LL dp[N], sum[N];
void norm(LL & x) {
	if (x < 0) x += mod;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector< pair<int,int> > a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<LL> r(m + 1, 0);
	
	for (int i = 1; i <= m; i ++) {
		LL tmpans = 1;
		LL tot = m / i, mx = m / i;
		dp[0] = 1; sum[0] = 1;
		for (int j = 1; j <= tot; j ++) {
			dp[j] = 0, sum[j] = 1;
		}
		for (int j = 0; j < n; j ++) {
			tot = tot - (a[j].first - 1) / i;
			int lim = a[j].second / i - (a[j].first - 1) / i;
			dp[0] = 0;
			for (int x = 1; x <= mx; x ++) {
				dp[x] = sum[x-1] - (x-1-lim>=0?sum[x-1-lim]:0);
				dp[x] = (dp[x] % mod + mod) % mod;
			}
			sum[0] = 0;
			for (int x = 1; x <= mx; x ++) {
				sum[x] = (sum[x-1] + dp[x]) % mod;
			}
		}
		if (tot >= 0)
			r[i] = sum[tot];
		//printf("i = %d, r = %lld\n", i, r[i]);
	}
	for (int i = m; i >= 1; i --) {
		for (int j = i + i; j <= m; j += i) {
			r[i] = ((r[i] - r[j]) % mod + mod) % mod;
		}
	}
	cout << r[1] << endl;
}