#include<bits/stdc++.h>

using namespace std;

#define NN 100011
typedef long long INT;
int n,a;
INT dp[NN],cnt[NN];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a);
		cnt[a]++;
	}
	dp[1] = cnt[1];
	for (int i=2; i<NN; i ++)  {
		dp[i] = max(dp[i-1], dp[i-2] + (INT)cnt[i] * i);
	}
	printf("%I64d\n", dp[NN-1]);
	return 0;
}