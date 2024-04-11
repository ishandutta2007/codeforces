#include <stdio.h>
#define N 110

char s[N][N];
bool fl[N];
int y[N], x[N];

int main() {
	int n, i, j;
//	freopen ("in.txt", "r", stdin);
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%s", s[i]);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) if (s[i][j]=='.') break;
		if (j==n) break;
		y[i]=j;
	}
	if (i<n) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) if (s[j][i]=='.') break;
			if (j==n) break;
			x[i]=j;
		}
		if (i<n) puts("-1");
		else for (i=0; i<n; i++) printf("%d %d\n", x[i]+1, i+1);
	} else for (i=0; i<n; i++) printf("%d %d\n", i+1, y[i]+1);
	return 0;
}