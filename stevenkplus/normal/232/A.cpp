#include <cstdio>

using namespace std;

const int N = 100;

bool adj[N][N];

int main() {
	int K;
	scanf("%d", &K);
	for(int i = 0; i < N; ++i) {
		int add = 0;
		for(int j = 0; j < i; ++j) {
			if (add <= K) {
				adj[i][j] = adj[j][i] = true;
				K -= add;
				++add;
			}
		}
	}

	printf("%d\n", N);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if (adj[i][j]) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}

	return 0;
}