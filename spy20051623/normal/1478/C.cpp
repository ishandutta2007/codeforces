#include <bits/stdc++.h>

using namespace std;

long long a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n + n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n + n, greater<long long>());
	for (int i = 0; i < n; ++i) {
		if (a[i + i] != a[i + i + 1]) {
			printf("NO\n");
			return;
		}
		if (i < n - 1 && a[i + i] == a[i + i + 2]) {
			printf("NO\n");
			return;
		}
		a[i] = a[i + i];
	}
	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2) {
			printf("NO\n");
			return;
		}
		a[i] >>= 1;
		a[i] -= sum;
		if (a[i] % (n - cnt)) {
			printf("NO\n");
			return;
		}
		a[i] /= n - cnt;
		if (a[i] <= 0) {
			printf("NO\n");
			return;
		}
		sum += a[i];
		++cnt;
	}
	printf("YES\n");
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