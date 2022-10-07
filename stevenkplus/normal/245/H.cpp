#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5000;

bool pal[MAXN][MAXN];
int sum1[MAXN][MAXN];
int sum2[MAXN][MAXN];

char str[MAXN];
int N, Q;

void go(int a, int b) {
	while (a >= 0 && b < N && str[a] == str[b]) {
		++pal[a][b];
		--a;
		++b;
	}
}

void go() {
	for(int i = 0; i < N; ++i) {
		go(i, i);
		go(i, i + 1);
	}

	for(int i = 0; i < N; ++i) {
		int cur = 0;
		for(int j = 0; j < N; ++j) {
			cur += pal[i][j];
			sum1[i][j] = cur;
		}
	}

	for(int j = 0; j < N; ++j) {
		int cur = 0;
		for(int i = N - 1; i >= 0; --i) {
			cur += sum1[i][j];
			sum2[i][j] = cur;
		}
	}
}

int main() {
	scanf("%s", str);
	N = strlen(str);

	go();

	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = sum2[a - 1][b - 1];
		printf("%d\n", ans);
	}

	return 0;
}