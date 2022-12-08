#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];
int r[100][100];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		int t = a[i];
		while (t) {
			++b[i];
			t >>= 1;
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		if (b[i] == b[i + 1] && b[i] == b[i - 1]) {
			printf("1\n");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		r[i][i] = a[i];
		for (int j = i + 1; j < n; ++j) {
			r[i][j] = r[i][j - 1] ^ a[j];
		}
	}
	int res = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			for (int k = i + 1; k < n; ++k) {
				if (r[j][i] > r[i + 1][k])
					res = min(res, k - j - 1);
			}
		}
	}
	if (res == 0x3f3f3f3f)
		printf("-1\n");
	else
		printf("%d\n", res);
	return 0;
}