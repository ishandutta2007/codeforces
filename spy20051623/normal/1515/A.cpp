#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve() {
	int n, x;
	scanf("%d%d", &n, &x);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum == x) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	sort(a, a + n);
	if (sum < x) {
		for (int i = 0; i < n; ++i) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	sum = 0;
	int tmp = -1;
	for (int i = 0; i < n; ++i) {
		if (sum + a[i] == x) {
			tmp = a[i];
		} else {
			printf("%d ", a[i]);
			sum += a[i];
		}
	}
	if (tmp != -1)
		printf("%d ", tmp);
	printf("\n");
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