#include <bits/stdc++.h>
using namespace std;

int f[21][11][5], g[21][11][5], n, t;

int main(){
	int i, j, k, s, ans = 0;
	scanf("%d %d", &n, &t);
	for(i = 1; i <= 4; i++) f[2][1][i] = i - 1;
	for(i = 1; i <= 4; i++) g[2][1][i] = 0;
	for(i = 3; i <= n; i++){
		for(j = 1; j <= t; j++){
			for(k = 1; k <= 4; k++){
				for(s = 1; s < k; s++) f[i][j][k] += f[i - 1][j][s] + g[i - 1][j - 1][s];
				for(s = k + 1; s <= 4; s++) g[i][j][k] += g[i - 1][j][s] + f[i - 1][j][s];
			}
		}
	}
	for(i = 1; i <= 4; i++) ans += g[n][t][i];
	printf("%d", ans);
}