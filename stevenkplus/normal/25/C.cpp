#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 310;

int adj[MAXN][MAXN];

int N, Q;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			scanf("%d", adj[i] + j);
		}
	}

	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		int a, b, len;
		scanf("%d %d %d", &a, &b, &len);
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				int &curdist = adj[i][j];
				int newdist1 = adj[i][a] + len + adj[b][j];
				int newdist2 = adj[i][b] + len + adj[a][j];
				if (newdist1 < curdist) curdist = newdist1;
				if (newdist2 < curdist) curdist = newdist2;
			}
		}

		ll sum = 0;
		for(int i = 1; i <= N; ++i) {
			for(int j = i + 1; j <= N; ++j) {
				sum += adj[i][j];
			}
		}

		if (q) printf(" ");
		printf("%I64d", sum);
	}
	printf("\n");
	return 0;
}