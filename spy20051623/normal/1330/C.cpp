#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	long long sum = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum < n) {
		printf("-1\n");
		return 0;
	}
	int p = n + 1;
	for (int i = m - 1; i >= 0; --i) {
		if (i + a[i] > n) {
			printf("-1\n");
			return 0;
		}
		if (i + a[i] < p) {
			b[i] = p - a[i];
			p = b[i];
		} else {
			b[i] = i + 1;
			p = b[i];
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d ", b[i]);
	}
	return 0;
}