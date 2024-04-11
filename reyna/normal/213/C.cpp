//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 320;
int dp[Maxn * 2][Maxn][Maxn];
int mat[Maxn][Maxn];
int n;
bool check(int now){
	if(now == -1 || now == n)
		return 0;
	return 1;
}
int main(){
	cin >> n;
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n;j++)
			cin >> mat[i][j];
	if(!(n-1)){
		cout << mat[0][0] << endl;
		return 0;
	}
	dp[0][0][0] = mat[0][0];
//	dp[1][0][1] = mat[0][0] + mat[0][1] + mat[1][0];
//	dp[1][1][0] = mat[0][0] + mat[1][0] + mat[0][1];
//	dp[1][0][0] = mat[0][0] + mat[0][1] + mat[0][1];
//	dp[1][1][1] = mat[0][0] + mat[1][0] + mat[1][0]; 
	for(int i = 1; i < 2 * n;i++){
		for(int j = 0; j < n;j++)
			for(int k = 0 ;k < n;k++)
				dp[i][j][k] = -900000001;
	}
	for(int sum = 1;sum < 2 * n - 1; sum++){
		for(int i = 0; i <= min(sum,n-1);i++){
			for(int j = 0; j <= min(sum,n-1);j++){
			//	if(i != j){
					int r = sum - i;
					int l = sum - j;
					if(r <= n-1 && l <= n-1)
						for(int a = -1; a < 1;a++){
							for(int b = -1; b < 1;b++){
								// r - a - 1
								// i + a
								// l - b - 1
								// j + b
								if(check(r-a-1) && check(i+a) && check(l-b-1) && check(j+b)){
									if(i != j)
										dp[sum][i][j] = max(dp[sum][i][j],dp[sum-1][i+a][j+b] + mat[i][r] + mat[j][l]);
									else
										dp[sum][i][j] = max(dp[sum][i][j],dp[sum-1][i+a][j+b] + mat[i][r]);
								}
							}
						}
			//	}
			}
		}
	}
	cout << dp[2*n-2][n-1][n-1] << endl;
	return 0;
}