#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;

const int N = 5000 + 10;

int n,a[N];
LL dp[N][N];
void upd(LL &x,LL y){
	(x+=y)%=MOD;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dp[n][n]=1;
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			//printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);
			// join i-1
			if(2*a[i-1]<=a[j]) {
				//printf("i=%d,j=%d\n", i,j);
				// i-1 is happy
				upd(dp[i-1][i-1], dp[i][j]);
				// i-1 is sad
				upd(dp[i-1][j], dp[i][j] * (n-i+1) % MOD);
			} else {
				upd(dp[i-1][j], dp[i][j] * (n-i) % MOD);
			}
		}
	}
	LL ans = 0;
	for(int i=1;i<=n;i++) (ans+=dp[1][i])%=MOD;
	cout<<ans<<endl;
}