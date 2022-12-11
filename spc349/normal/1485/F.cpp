#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int a[200010];
long long pw[200010];
map <long long, long long> all;

int main () {
	pw[0] = 1;
	for (int i = 1; i <= 200005; i++) {
		pw[i] = pw[i - 1] * 2 % mod;
	}
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		all.clear();
		long long base = 0, sum = 1;
		all[0] = 1;
		for (int i = 1; i <= n; i++) {
			long long nsum = (sum + sum - all[-base] + mod) % mod;
			all[-base] = sum;
			base += a[i], sum = nsum;
		}
		printf("%lld\n", sum);
	}
	return 0;
}