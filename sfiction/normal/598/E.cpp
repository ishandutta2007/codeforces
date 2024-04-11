#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30 + 2, MAXK = 50;
const int INF = 1 << 30;

int n = 30, m = 30, k;
int f[MAXN][MAXN][MAXK + 1];

int main(){
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j){
			int limit = min(n * m, MAXK);
			for (int k = 0; k <= limit; ++k){
				if (k == 0 || k == i * j){
					f[i][j][k] = f[j][i][k] = 0;
					continue;
				}
				f[i][j][k] = INF;
				for (int ii = i >> 1; ii >= 1; --ii){
					for (int kk = 0; kk <= k; ++kk)
						if (ii * j >= kk && (i - ii) * j >= k - kk)
							f[i][j][k] = min(f[i][j][k], f[ii][j][kk] + f[i - ii][j][k - kk] + j * j);
				}
				for (int jj = j >> 1; jj >= 1; --jj){
					for (int kk = 0; kk <= k; ++kk)
						if (i * jj >= kk && i * (j - jj) >= k - kk)
							f[i][j][k] = min(f[i][j][k], f[i][jj][kk] + f[i][j - jj][k - kk] + i * i);
				}
				f[j][i][k] = f[i][j][k];
			}
		}

	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", f[n][m][k]);
	}
	return 0;
}