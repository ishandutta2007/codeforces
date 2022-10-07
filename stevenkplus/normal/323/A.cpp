#include <cstdio>

int K;

int main() {
	scanf("%d", &K);
	if (K % 2 == 1) {
		printf("-1\n");
	} else {
		for(int i = 0; i < K; ++i) {
			for(int j = 0; j < K; ++j) {
				for(int k = 0; k < K; ++k) {
					if ((k / 2) % 2 == ((j / 2) % 2) == (i % 2 == 0)) {
						printf("b");
					} else {
						printf("w");
					}
				}
				printf("\n");
			}
			if (i + 1 < K)
				printf("\n");
		}
	}
	return 0;
}