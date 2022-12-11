#include <bits/stdc++.h>
using namespace std;

int vis[510][510], a[510];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x = i, y = i, T = a[i];
		while (T--) {
			vis[x][y] = a[i];
			if (y && !vis[x][y - 1]) y--;
			else x++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", vis[i][j]);
		}
		printf("\n");
	}
	return 0;
}