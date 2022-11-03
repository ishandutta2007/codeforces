/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 543A
 */
#include <cstdio>
#include <cstring>

const int MAXN = 5E2 + 10;

int f[MAXN][MAXN];

int main(){
	int n, m, b, mod;
	scanf("%d%d%d%d", &n, &m, &b, &mod);

	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int k=0;k<n;++k){
		int a;
		scanf("%d", &a);
		for (int i=1;i<=m;++i)
			for (int j=a;j<=b;++j)
				f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
	}

	int ans = 0;
	for (int i=0;i<=b;++i)
		ans = (ans + f[m][i]) % mod;
	printf("%d\n", ans);
	
	return 0;
}