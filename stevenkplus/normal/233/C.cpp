#include <cstdio>

using namespace std;

const int MAXN = 100;
int adj[MAXN][MAXN];

int main() {
	int M;
	scanf("%d", &M);
	for(int i = 0; i < MAXN; ++i) {
		int sum = 0;
		for(int j = 0; j < i && sum <= M; ++j) {
			M -= sum;
			sum++;
			adj[i][j] = adj[j][i] = true;
		}
	}
	printf("%d\n", MAXN);
	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			int k = adj[i][j]?1:0;
			printf("%d", k);
		}
		printf("\n");
	}
	return 0;
}