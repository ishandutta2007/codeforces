#include <cstdio>

using namespace std;

int N;

int main() {
	scanf("%d", &N);
	if (N % 2 == 0) {
		printf("-1\n");
	} else {
		for(int i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", i);
		}
		printf("\n");
		for(int i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", i);
		}
		printf("\n");
		for(int i = 0; i < N; ++i) {
			if (i) printf(" ");
			int x = (i * 2) % N;
			printf("%d", x);
		}
		printf("\n");
	}
	return 0;
}