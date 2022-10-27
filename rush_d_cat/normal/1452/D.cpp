#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;
int n;
LL dp[N][2];

LL INV  = (MOD + 1) / 2;
void upd(LL &x,LL y){
	x+=y; x%=MOD;
}
int main() {
	cin >> n;

	dp[0][0] = 1; dp[0][1] = 0;
	for (int i = 0; i <= n; i ++) {
		//printf("dp[%d] = {%lld,%lld}\n", i,dp[i][0],dp[i][1]);
		if(i<n) upd(dp[i+1][1], dp[i][0] * INV % MOD); // no
		if(i<n)upd(dp[i+1][0], dp[i][0] * INV % MOD); // yes
		else upd(dp[i+1][0], dp[i][1]);

		if(i<n) upd(dp[i+1][0], dp[i][1] * INV % MOD); // no
	}
	printf("%lld\n", dp[n+1][0]);

}