//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 505;
int c[Maxn],dp[Maxn][Maxn];
int main(){
	int n,m,b,Mod;
	cin >> n >> m >> b >> Mod;
	for(int i = 0; i < n;i++) cin >> c[i];
	dp[0][0] = 1;
	for(int i = 0; i < n;i++){
		for(int j = 0; j <= b;++j){
			if(j >= c[i])
			for(int k = 1; k <= m;k++){
				dp[j][k] += dp[j-c[i]][k-1];
				dp[j][k] %= Mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= b;i++)
		ans += dp[i][m],ans %= Mod;
	cout << ans << endl;
	return 0;
}