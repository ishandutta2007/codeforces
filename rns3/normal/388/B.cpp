#include <bits/stdc++.h>
using namespace std;

#define N 1010
const int D = 30;

int k, n;
bool tag[N][N];

int main() {
	scanf("%d", &k);
	n = 31;
	for (int i = 3; i <= 31; i ++) tag[i][i-1] = 1;
	for (int t = 0; t <= 29; t ++) if (k & (1 << t)) {
		if (!t) {
			tag[31][1] = 1;
			continue;
		}
		int now = 31 - t;
		tag[now][++n] = 1;
		tag[now][++n] = 1;
		for (int i = 1; i < t; i ++) {
            tag[n-1][n+1] = 1;
            tag[n-1][n+2] = 1;
            tag[n][n+1] = 1;
            tag[n][n+2] = 1;
            n += 2;
		}
		tag[n-1][1] = tag[n][1] = 1;
	}
	printf("%d\n", n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (tag[i][j] | tag[j][i]) printf("Y");
			else printf("N");
		}
		puts("");
	}
	return 0;
}