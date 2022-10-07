#include <cstdio>

const int MAXN = 100100;
int N;

int main() {
	scanf("%d", &N);
	if (N % 4 == 0 || N % 4 == 1) {
		for(int i = 1; i <= N; ++i) {
			if (i != 1) printf(" ");
			if (i * 2 < N + 1) {
				if (i % 2 == 1) {
					printf("%d", i + 1);
				} else {
					printf("%d", N + 2 - i);
				}
			} else if (i * 2 == N + 1) {
				printf("%d", i);
			} else {
				if ((N - i) % 2 == 0) {
					printf("%d", i - 1);
				} else {
					printf("%d", N - i);
				}
			}
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
	return 0;
}