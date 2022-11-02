#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int dir[] = { 0, 1, 0, -1 };
int N, K, c, a[509][509], sd[509][509], z[250009], d[250009]; string s[509];
int sq(int x, int y) {
	return sd[x][y] + sd[x + K][y + K] - sd[x][y + K] - sd[x + K][y];
}
void dfs(int x, int y) {
	a[x][y] = c; z[c]++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i], ty = y + dir[i ^ 1];
		if (0 <= tx && tx < N && 0 <= ty && ty < N && s[tx][ty] == '.' && a[tx][ty] == -1) {
			dfs(tx, ty);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		fill(a[i], a[i] + N, -1);
		for (int j = 0; j < N; j++) {
			if (s[i][j] == 'X') sd[i + 1][j + 1] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == -1 && s[i][j] == '.') dfs(i, j), c++;
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sd[i][j] += sd[i][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			sd[i][j] += sd[i - 1][j];
		}
	}
	int ret = 0;
	for (int i = 0; i <= N - K; i++) {
		fill(d, d + c, 0);
		int sum = 0;
		for (int j = -1; j <= K; j++) {
			if (i + j < 0 || N <= i + j) continue;
			for (int k = 0; k < K; k++) {
				if (a[i + j][k] != -1) {
					if (!d[a[i + j][k]]) sum += z[a[i + j][k]];
					d[a[i + j][k]]++;
				}
			}
		}
		if (N != K) {
			for (int j = 0; j < K; j++) {
				if (a[i + j][K] != -1) {
					if (!d[a[i + j][K]]) sum += z[a[i + j][K]];
					d[a[i + j][K]]++;
				}
			}
		}
		ret = max(ret, sum + sq(i, 0));
		for (int j = K; j < N; j++) {
			for (int k = 0; k < K; k++) {
				if (j != K) {
					if (a[i + k][j - K - 1] != -1) {
						d[a[i + k][j - K - 1]]--;
						if (!d[a[i + k][j - K - 1]]) sum -= z[a[i + k][j - K - 1]];
					}
				}
				if (j + 1 != N) {
					if (a[i + k][j + 1] != -1) {
						if (!d[a[i + k][j + 1]]) sum += z[a[i + k][j + 1]];
						d[a[i + k][j + 1]]++;
					}
				}
			}
			if (i != 0) {
				if (a[i - 1][j - K] != -1) {
					d[a[i - 1][j - K]]--;
					if (!d[a[i - 1][j - K]]) sum -= z[a[i - 1][j - K]];
				}
				if (a[i - 1][j] != -1) {
					if (!d[a[i - 1][j]]) sum += z[a[i - 1][j]];
					d[a[i - 1][j]]++;
				}
			}
			if (i != N - K) {
				if (a[i + K][j - K] != -1) {
					d[a[i + K][j - K]]--;
					if (!d[a[i + K][j - K]]) sum -= z[a[i + K][j - K]];
				}
				if (a[i + K][j] != -1) {
					if (!d[a[i + K][j]]) sum += z[a[i + K][j]];
					d[a[i + K][j]]++;
				}
			}
			ret = max(ret, sum + sq(i, j - K + 1));
		}
	}
	cout << ret << endl;
	return 0;
}