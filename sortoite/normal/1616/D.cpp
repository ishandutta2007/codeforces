#include<bits/stdc++.h>
using namespace std;
const int NN = 5e4 + 10;
int a[NN], n, x;
int dp[NN][3];
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		scanf("%d", & n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
		}
		scanf("%d", & x);
		for(int i = 1; i <= n; i ++) {
			a[i] -= x;
		}
		dp[1][0] = 0;
		dp[1][1] = 1;
		dp[1][2] = - 1;
		for(int i = 2; i <= n; i ++) {
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
			dp[i][1] = dp[i - 1][0] + 1;
			if(a[i - 1] + a[i] < 0) dp[i][2] = - 1;
			else {
				dp[i][2] = dp[i - 2][0] + 2;
				if(dp[i - 1][2] >= 0 && a[i - 2] + a[i - 1] + a[i] >= 0) dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
			}
		}
		printf("%d\n", max({dp[n][0], dp[n][1], dp[n][2]}));
	}
	return 0;
}