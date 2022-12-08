#include <bits/stdc++.h>

using namespace std;

int a[200];
int b[200];
int vis[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		for (b[i] = 0;; ++b[i]) {
			if (a[i] % (1 << b[i]))
				break;
		}
		--b[i];
		sum += a[i];
	}
	if (sum % 2) {
		printf("0\n");
		return 0;
	}
	vis[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = sum / 2; j >= 0; --j) {
			if (vis[j])
				vis[j + a[i]] = 1;
		}
	}
	if (!vis[sum / 2]) {
		printf("0\n");
		return 0;
	}
	int m = 0;
	for (int i = 1; i < n; ++i) {
		if (b[i] < b[m])
			m = i;
	}
	printf("1\n");
	printf("%d\n", m + 1);
	return 0;
}