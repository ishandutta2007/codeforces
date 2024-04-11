#include <stdio.h>
#define N 2010

double f[N][N];
bool chk1[N], chk2[N];

int main() {
	int n, m, i, j, a, b;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &i, &j);
		chk1[i]=chk2[j]=1;
	}
	a=b=n;
	for (i=1; i<=n; i++) a-=chk1[i], b-=chk2[i];
	for (i=0; i<=a; i++) for (j=0; j<=b; j++) {
		if (!i && !j) {
			f[i][j]=0;
			continue;
		}
		f[i][j]=1.0*n*n/(n*i+n*j-i*j);
		if (i) f[i][j]+=f[i-1][j]*i*(n-j)/(n*i+n*j-i*j);
		if (j) f[i][j]+=f[i][j-1]*j*(n-i)/(n*i+n*j-i*j);
		if (i && j) f[i][j]+=f[i-1][j-1]*i*j/(n*i+n*j-i*j);
	}
	printf("%.10lf\n", f[a][b]);
}