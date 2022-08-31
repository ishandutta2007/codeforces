#include <bits/stdc++.h>
#define maxn 55
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
char inp[maxn][maxn]; 
int dp[maxn][maxn][maxn][maxn];
int cal(int a, int b, int c, int d) {
	if (a > b || c > d) return 0;
	if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
	dp[a][b][c][d] = max((b - a), (d - c)) + 1;
	if (a == b && c == d) {
		if (inp[a][c] == '.') dp[a][b][c][d] = 0;	
	//	cout << a << " " << b << " " << c << " " << d << " " << dp[a][b][c][d] << endl;
		return dp[a][b][c][d];
	}
	if (d - c > b - a) 
	{
		for (int j = c; j <= d; j++)
			dp[a][b][c][d] = min(dp[a][b][c][d], cal(a, b, c, j) + cal(a, b, j + 1, d));
	//	cout << "???" << endl;
	}
	else 
		for (int j = a; j <= b; j++)
			dp[a][b][c][d] = min(dp[a][b][c][d], cal(a, j, c, d) + cal(j + 1, b, c, d));
//	cout << a << " " << b << " " << c << " " << d << " " << dp[a][b][c][d] << endl;
	return dp[a][b][c][d];
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", inp[i]);
	memset(dp, -1, sizeof(dp));
	int ans = cal(0, n - 1, 0, n - 1);
	cout << ans << endl;
	return 0;
} 
/*
2 1 1 5

 
*/