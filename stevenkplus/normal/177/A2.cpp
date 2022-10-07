#include <cstdio>

using namespace std;

const int MAXN = 110;
int ar[MAXN][MAXN];

int N;

bool isGood(int x, int y) {
	return x == y || x + y == N - 1 || x + x == N - 1 || y + y == N - 1;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", ar[i] + j);
		}
	}
	int sum = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if (isGood(i, j)) {
				sum += ar[i][j];
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}