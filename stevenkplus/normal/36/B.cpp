#include <cstdio>

using namespace std;

const int MAXN = 310;

bool grid[MAXN][MAXN];
char gen[5][5];

int N, K;

bool fill(int x, int y) {
	for(int i = 0; i < K; ++i) {
		if (gen[x % N][y % N] == '*') {
			return true;
		}
		x /= N;
		y /= N;
	}
	return false;
}

int pow(int a, int b) {
	int prod = 1;
	for(int i = 0; i < b; ++i) {
		prod *= a;
	}
	return prod;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		scanf("%s", gen[i]);
	}

	int size = pow(N, K);
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if (fill(i, j)) {
				printf("*");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}