#include<stdio.h>
#include<cstring>
#define min(a,b) (a < b? a : b)

const int N = 505;
int n, a[N], f[N][N], g[N]; 

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i][i] = a[i];
	for(int i = n; i >= 1; i--)
		for(int j = i; j <=n; j++)
			for(int k = i; k < j; k++)
				if(f[i][k] * f[k + 1][j] && f[i][k] == f[k + 1][j])
					f[i][j] = f[i][k] + 1;
	memset(g, 0x3f, sizeof(g)), g[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			g[i] = min(g[i], g[j - 1] + (f[j][i] > 0? 1 : (i - j + 1)));
	printf("%d\n", g[n]);
	return 0;
}