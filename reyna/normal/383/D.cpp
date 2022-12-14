//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int Maxn = 1e4 + 9;
int dp[Maxn];
int last[Maxn];
int main(){
	int n;
	cin >> n;
	dp[Maxn / 2] = 1;
	int ans = 0;
	for(int i = 0; i < n;i++){
		int p;
		cin >> p;
		for(int j = 0; j < Maxn;j++) last[j] = dp[j];
		for(int j = 0; j < Maxn;j++) {
			dp[j] = 0;
			if(j >= p) dp[j] += last[j - p];
			if(j + p < Maxn) dp[j] += last[j + p];
			dp[j] %= Mod;
		}
		ans += dp[Maxn / 2];
		ans %= Mod;
		dp[Maxn / 2]++;
		dp[Maxn / 2] %= Mod;
	}
	cout << ans << endl;
}