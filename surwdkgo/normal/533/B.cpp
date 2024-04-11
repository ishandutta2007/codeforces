#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
typedef long long LL;
int d[2000010], p[2000010];
LL dp[2000010][2];
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &p[i], &d[i]);
		p[i] --;
		dp[i][1] = -1000000000000000ll;
	}
	for (int i=n-1; i>=0; i--) {
		dp[i][1] = max(dp[i][1], dp[i][0] + d[i]);
		if (!i) break;
		LL nv0, nv1;
		nv0 = max(dp[p[i]][0]+dp[i][0], dp[p[i]][1]+dp[i][1]);
		nv1 = max(dp[p[i]][0]+dp[i][1], dp[p[i]][1]+dp[i][0]);
		dp[p[i]][0] = nv0, dp[p[i]][1] = nv1;
	}
	cout << dp[0][1] << endl;
	return 0;
}