#include <bits/stdc++.h>

using namespace std;

long long a[5005];
long long b[5005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &b[i]);
	}
	long long maxm = 0;
	for (int i = 0; i < n + n - 1; ++i) {
		long long res = 0;
		for (int j = i / 2; j >= 0 && i - j < n; --j) {
			int k = i - j;
			res -= (a[j] - a[k]) * (b[j] - b[k]);
			maxm = max(maxm, res);
		}
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[i];
	}
	printf("%lld\n", sum + maxm);
	return 0;
}