#include <bits/stdc++.h>
using namespace std;

#define N 12

int n, m, row[N] = {0}, col[N] = {0};
char s[N][N];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i ++) {
		gets(s[i]);
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == 'S') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; i ++) if (row[i]) x ++;
	for (int j = 0; j < m; j ++) if (col[j]) y ++;
	printf("%d\n", n * m - x * y);
	return 0;
}