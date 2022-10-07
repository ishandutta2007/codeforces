#include <cstdio>

using namespace std;

const int scal = 696;

int f(int x) {
	return x * x + 696969;
}

int N, M;
int main() {
	scanf("%d %d", &N, &M);
	if (M == 3) {
		if (N == 3) {
			printf("0 0\n0 1\n1 1\n");
		} else if (N == 4) {
			printf("0 0 1 1 2 0 1 2\n");
		} else {
			printf("-1\n");
		}
		return 0;
	}

	int extr = N - M;
	for(int i = 0; i < M; ++i) {
		printf("%d %d\n", i, f(i));
	}

	for(int i = 0; i < extr; ++i) {
		printf("%d %d\n", i, -f(i));
	}
	return 0;
}