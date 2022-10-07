#include <cstdio>

const int MAXN = 10;

int grid[MAXN][MAXN];
char tmp[MAXN];

int N = 4;

int main() {
	for(int i = 0; i < N; ++i) {
		scanf("%s", tmp);
		for(int j = 0; j < N; ++j) {
			grid[i][j] = tmp[j] == '.';
		}
	}

	for(int i = 0; i + 1 < N; ++i) {
		for(int j = 0; j + 1 < N; ++j) {
			int sum = grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
			if (sum != 2) {
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}