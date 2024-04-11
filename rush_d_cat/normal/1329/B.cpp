#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL d,m;
LL dp[50][50];
LL solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=0;
	int pw=1,high=0;
	while(pw<=d) {
		pw*=2;
		if(pw<=d) high++;
	}
	high++;
	dp[0][0] = 1;
	for(int i=0;i<=high;i++){
		for(int j=0;j<=high;j++){
			// dp[i][j] -> dp[i+1][k]
			for(int k=j+1;k<=high;k++){
				if(k!=high)
					(dp[i+1][k] += (1LL*dp[i][j]*(1LL<<(k-1))%m) ) %= m;
				else {
					LL val = d - (1LL << (high-1)) + 1;
					dp[i+1][k] = (dp[i+1][k] + (1LL*dp[i][j]*val%m)) % m;
				}
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=high;i++)for(int j=0;j<=high;j++) (ans+=dp[i][j]) %= m;
	printf("%lld\n", ans);
	return ans;
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&d,&m);
		solve();
	}
}