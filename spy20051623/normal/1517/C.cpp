#include <bits/stdc++.h>

using namespace std;

int mp[505][505];
int a[505];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	memset(mp, -1, sizeof mp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			mp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		mp[i][i] = a[i];
		int x = i;
		int y = i;
		int k = a[i] - 1;
		while (k--) {
			if (!mp[x][y - 1]) {
				mp[x][y - 1] = a[i];
				--y;
			} else {
				mp[x + 1][y] = a[i];
				++x;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d ", mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}