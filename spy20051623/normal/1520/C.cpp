#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	if (n == 1)
		printf("1\n");
	else if (n == 2)
		printf("-1\n");
	else {
		int p[105][105];
		int s = 1, t = n * n / 2 + 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i + j) % 2)
					p[i][j] = s++;
				else
					p[i][j] = t++;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", p[i][j]);
			}
			printf("\n");
		}
	}
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