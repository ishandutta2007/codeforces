#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, k;
char a[N][N];
int up[N], dwn[N], l[N], r[N];
int cnth[N][N], cnts[N][N], ans;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) up[i] = l[i] = n + 1;
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
		for(int j = 1; j <= n; j++) {
			if(a[i][j] == 'B') 
				l[i] = min(l[i], j), up[j] = min(up[j], i),
				r[i] = max(r[i], j), dwn[j] = max(dwn[j], i);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cnth[i][j] = cnth[i - 1][j] + (l[i] >= (j - k + 1) && (r[i] <= j) && (l[i] != n + 1));
			cnts[i][j] = cnts[i][j - 1] + (up[j] >= (i - k + 1) && (dwn[j] <= i) && (up[j] != n + 1));
		}
		ans += (l[i] == n + 1) + (up[i] == n + 1);
	}
	int maxn = 0;
	for(int i = k; i <= n; i++) {
		for(int j = k; j <= n; j++) {
			maxn = max(maxn, cnth[i][j] - cnth[i - k][j] + cnts[i][j] - cnts[i][j - k]);
		}
	}
	printf("%d\n", ans + maxn);
	return 0;
}

/*
4 2
BBBB
BWWW
BWWW
BWWW
*/