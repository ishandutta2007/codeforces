#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 60

int main() {
	char t[N][N];
	int n, m, a, b, c, d;
	scanf("%d %d\n", &n, &m);
	a = n, b = 0, c = m, d = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%s", t[i]);
		for (int j = 0; j < m; j ++) {
			if (t[i][j] == '*') {
				a = min(a, i);
				b = max(b, i);
				c = min(c, j);
				d = max(d, j);
			}
		}
	}
	for (int i = a; i <= b; i ++) {
		for (int j = c; j <= d; j ++) printf("%c", t[i][j]);
		puts("");
	}
	return 0;
}