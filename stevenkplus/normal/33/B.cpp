#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int inf = 1 << 29;
const int MAXC = 50;
const int MAXN = 100100;

int adj[MAXC][MAXC];
int conv[MAXC][MAXC];
int fin[MAXC][MAXC];

void floyd() {
	for(int k = 0; k < MAXC; ++k) {
		for(int i = 0; i < MAXC; ++i) {
			for(int j = 0; j < MAXC; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

void go() {
	for(int i = 0; i < MAXC; ++i) {
		for(int j = 0; j < MAXC; ++j) {
			conv[i][j] = inf;
			for(int k = 0; k < MAXC; ++k) {
				int d = adj[i][k] + adj[j][k];
				if (d < conv[i][j]) {
					conv[i][j] = d;
					fin[i][j] = k;
				}
			}
		}
	}
}

int N, M;
char str1[MAXN], str2[MAXN];
char ans[MAXN];

int main() {
	scanf("%s", str1);
	scanf("%s", str2);
	N = strlen(str1);
	if (strlen(str2) != N) {
		printf("-1\n");
		return 0;
	}

	for(int i = 0; i < MAXC; ++i) {
		for(int j = 0; j < MAXC; ++j) {
			adj[i][j] = inf;
		}
		adj[i][i] = 0;
	}

	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
		int a, b, c;
		char ac, bc;
		scanf(" %c %c %d", &ac, &bc, &c);
		a = ac - 'a';
		b = bc - 'a';
		adj[a][b] = min(adj[a][b], c);
	}

	floyd();
	go();

	int sum = 0;
	bool nosol = false;
	for(int i = 0; i < N; ++i) {
		int a = str1[i] - 'a';
		int b = str2[i] - 'a';
		if (conv[a][b] == inf) {
			nosol = true;
			break;
		}
		sum += conv[a][b];
		ans[i] = 'a' + fin[a][b];
	}

	if (nosol) {
		printf("-1\n");
	} else {
		printf("%d\n", sum);
		printf("%s\n", ans);
	}
	return 0;
}