#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
const int mod = 998244353;
int a[N];
long long p[N], q[N];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		p[i] = q[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			p[0] = (p[0] + p[0] + 1) % mod;
			q[2] = (q[2] + q[2]) % mod;
		} else if (a[i] == 1) {
			p[1] = (p[1] + p[0] + p[1]) % mod;
			q[1] = (q[1] + q[1] + 1) % mod;
			q[3] = (q[3] + q[3]) % mod;
		} else {
			int z = a[i];
			p[z] = (p[z] + p[z - 1] + p[z]) % mod;
			q[z] = (q[z] + q[z] + p[z - 2]) % mod;
			q[z + 2] = (q[z + 2] + q[z + 2]) % mod;
		}
	}
	for (int i = 0; i <= n; ++i) {
		ans += p[i] + q[i];
	}
	ans %= mod;
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}