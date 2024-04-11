#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 350;
const int Mod = 1e9 + 7;

int dp[2][N][N];

void add(int &x, int y){
	x += y;
	if(x >= Mod) x -= Mod;
}

int n, m, x;

int main(){

	scanf("%d%d%d", &m, &n, &x);
	
	if(m > n){
		puts("0");
		return 0;
	}

	int i = 0;
	dp[0][0][0] = 1;

	For(u, 1, n){
		For(j, 0, m) For(k, 0, j){
			int &val = dp[i][j][k];
			if(!val) continue;

			if(j < m){
				add(dp[i ^ 1][j + 1][k + 1], val);
				add(dp[i ^ 1][j + 1][k], val);
			}

			if(u ^ x){
				if(k < j) add(dp[i ^ 1][j][k + 1], val);
				add(dp[i ^ 1][j][k], val);
			}

			val = 0;
		}
		i ^= 1;
	}

	int ans = dp[i][m][m];
	For(s, 1, m) ans = 1ll * s * ans % Mod * 1;
	printf("%d\n", ans);

	return 0;
}