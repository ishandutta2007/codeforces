//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 5e3 + 9;
const ll Mod = 1e9 + 7;
ll dp[Maxn][Maxn];
int main(){
	int n,k,a,b;
	cin >> n >> a >> b >> k;
	dp[0][--a] = 1;
	--b;
	for(int lv = 1; lv <= k;lv++){
		ll sum = 0;
		if(a < b){
			int p = 0;
			while(b - p > p) sum += dp[lv-1][p],sum %= Mod,p++;
			for(int i = 0; i < b;i++){
				while(b - p > p - i) sum += dp[lv-1][p],p++;
				dp[lv][i] = sum - dp[lv-1][i] + Mod;
				dp[lv][i] %= Mod;
			}
		}else{
			int p = n-1;
			while(n - 1 - p < p - b) sum += dp[lv-1][p],sum %= Mod,p--;
			for(int i = n-1; i > b;i--){
				while(i - p < p - b) sum += dp[lv-1][p],sum %= Mod,p--;
				dp[lv][i] = sum - dp[lv-1][i] + Mod;
				dp[lv][i] %= Mod;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < n;i++) ans += dp[k][i],ans %= Mod;
	cout << ans << endl;
	return 0;
}