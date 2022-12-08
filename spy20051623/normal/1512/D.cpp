#include <bits/stdc++.h>

using namespace std;

long long b[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n + 2; ++i) {
		scanf("%lld", &b[i]);
	}
	sort(b, b + n + 2);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += b[i];
	}
	long long tmp = sum + b[n] - b[n + 1];
	if (tmp >= b[0] && tmp <= b[n]) {
		int pos = lower_bound(b, b + 1 + n, tmp) - b;
		if (b[pos] == tmp) {
			for (int i = 0; i < n + 1; ++i) {
				if (i != pos)
					printf("%lld ", b[i]);
			}
			printf("\n");
			return;
		}
	}
	if (sum == b[n]) {
		for (int i = 0; i < n; ++i) {
			printf("%lld ", b[i]);
		}
		printf("\n");
		return;
	}
	printf("-1\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}