#include <bits/stdc++.h>

using namespace std;

int evensXOR(const vector<vector<int>> &grid) {
	int n = grid.size();
	vector<int> diagSum(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			diagSum[j-i] ^= grid[i][j];
		}
	}
	for (int i = 1; i < n; i += 2) {
		for (int j = ((i % 4 == 1) ? 2 : 0); j < n; j += 4) {
			ans ^= grid[i][j];
		}
	}
	for (int i = 0; i < n; i += 4) {
		ans ^= diagSum[i+1];
	}
	return ans;
}

int solve() {
	int n; scanf("%d", &n);
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);	
		}
	}
	int ans = evensXOR(grid);
	for (int i = 0; i < n; ++i) {
		for (int j1 = 0, j2 = n - 1; j1 < j2; ++j1, --j2) {
			swap(grid[i][j1], grid[i][j2]);
		}
	}
	ans ^= evensXOR(grid);
	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		printf("%d\n", solve());
	}
	return 0;
}