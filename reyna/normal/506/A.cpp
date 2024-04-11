//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 3e4 + 100;
const int MaxL = 900;
long long dp[Maxn][MaxL];
int num[Maxn];
int main(){
	int n,d;
	cin >> n >> d;
	for(int i = 0; i < n;i++){
		int now;
		cin >> now;
		num[now]++;
	}
	for(int i = 0; i < Maxn;i++)
		for(int j = 0; j < MaxL;j++)
			dp[i][j] = (-Maxn) * 2;
	dp[d][420] = num[d];
	long long ans = 0;
	ans = num[d];
	for(int i = d+1; i < 30001;i++){
		for(int j = max(d - 400,1);j < d + 400;j++){
			if(i < j)
				continue;
			if(d - j + 420)
			dp[i][d - j + 420] = max(dp[i-j][d - j + 420]+num[i],dp[i][d-j+420]);
			if(d - j + 420-1)
			dp[i][d-j+420] = max(dp[i-j][d - j + 420 - 1]+num[i],dp[i][d-j+420]);
			if(d - j + 420+1)
			dp[i][d-j+420] = max(dp[i-j][d-j+420+1]+num[i],dp[i][d-j+420]);
			ans = max(ans,dp[i][d-j+420]);
//			if(num[i] && i < 29)
//			cerr << i << ' ' << j << ' ' << dp[i][d-j+420] << endl;
		}
	}
	cout << ans << endl;
	return 0;
}