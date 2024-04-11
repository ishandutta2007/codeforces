#include <bits/stdc++.h>

using namespace std;

#define NN 5000
int n,a,b,c;
int dp[NN];
int main() {
	cin>>n>>a>>b>>c;
	memset (dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int i=1; i <=n; i ++) {
		if (i>=a && dp[i-a]>=0) dp[i] = max(dp[i], dp[i-a] + 1);
		if (i>=b && dp[i-b]>=0) dp[i] = max(dp[i], dp[i-b] + 1);
		if (i>=c && dp[i-c]>=0) dp[i] = max(dp[i], dp[i-c] + 1);
	}
	printf("%d\n", dp[n]);
}