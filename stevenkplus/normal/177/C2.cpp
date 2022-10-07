#include <cstdio>

using namespace std;

const int MAXN = 2010;

int par[MAXN];
int sizes[MAXN];

int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[a] = b;
		sizes[b] += sizes[a];
	}
}

int N, K, M;

bool bad[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		par[i] = i;
		sizes[i] = 1;
	}

	scanf("%d", &K);
	for(int i = 0; i < K; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}

	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) == find(b)) {
			bad[find(a)] = true;
		}
	}

	int ans = 0;
	for(int i = 1; i <= N; ++i) {
		if (par[i] == i) {
			if (!bad[i]) {
				if (sizes[i] > ans) {
					ans = sizes[i];
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}