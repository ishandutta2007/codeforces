#include<bits/stdc++.h>
using namespace std;

#define N 120
int n, m;
char s[N][N];

int main() {
	 scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (s[i][j] == 'B') {
		int jj = j;
		while (jj <= m && s[i][jj] == 'B') jj ++;
		int ii = i;
		while (ii <= n && s[ii][j] == 'B') ii ++;
		printf("%d %d\n", (i + ii - 1) / 2, (j + jj - 1) / 2);
		return 0;
	}
}