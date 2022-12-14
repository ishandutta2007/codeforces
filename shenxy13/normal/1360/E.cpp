#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		char mat[n][n];
		bool reach[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) scanf(" %c", &mat[i][j]);
		}
		for (int i = 0; i < n; ++i) reach[n - 1][i] = mat[n - 1][i] == '1';
		for (int i = 0; i < n; ++i) reach[i][n - 1] = mat[i][n - 1] == '1';
		for (int i = n - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) reach[i][j] = mat[i][j] == '1' && (reach[i][j + 1] || reach[i + 1][j]);
		}
		bool can = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) can &= reach[i][j] == (mat[i][j] == '1');
		}
		printf(can ? "YES\n" : "NO\n");
	}
	return 0;
}