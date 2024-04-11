#include <bits/stdc++.h>

using namespace std;

int minX[10], minY[10], maxX[10], maxY[10];
int ans[10];
int a[2005][2005];

void solve() {
	memset(minX, 63, sizeof minX);
	memset(minY, 63, sizeof minY);
	memset(maxX, 0, sizeof maxX);
	memset(maxY, 0, sizeof maxY);
	memset(ans, 0, sizeof ans);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &a[i][j]);
			int &p = a[i][j];
			minX[p] = min(minX[p], i);
			minY[p] = min(minY[p], j);
			maxX[p] = max(maxX[p], i);
			maxY[p] = max(maxY[p], j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int &p = a[i][j];
			ans[p] = max(ans[p], max(i - minX[p], maxX[p] - i) * max(j, n - 1 - j));
			ans[p] = max(ans[p], max(j - minY[p], maxY[p] - j) * max(i, n - 1 - i));
		}
	}
	for (int an : ans) {
		printf("%d ", an);
	}
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