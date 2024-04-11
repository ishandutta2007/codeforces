#include <cstdio>

using namespace std;

int N, K;

int main() {
	scanf("%d %d", &N, &K);
	int best = N * (N - 1) / 2;
	if (best > K) {
		for(int i = 0; i < N; ++i) {
			printf("0 %d\n", i);
		}
	} else {
		printf("no solution\n");
	}
	return 0;
}