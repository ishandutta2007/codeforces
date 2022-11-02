#include<bits/stdc++.h>
#define NN 1000001

using namespace std;

int a[NN];
long long dp[NN], ans;

inline bool linear(int u) {
	if(a[u-1]>=a[u] && a[u]>=a[u+1]) return true;
	return a[u-1]<=a[u] && a[u]<=a[u+1];
}

main() {
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	
	for(int i=2; i<=n; i++) {
		if(linear(i-1)) dp[i]=dp[i-1]+abs(a[i]-a[i-1]);
		else dp[i]=max(dp[i-1], dp[i-2]+abs(a[i]-a[i-1]));
		if(ans<dp[i]) ans=dp[i];
	}
	printf("%I64d", ans);
}