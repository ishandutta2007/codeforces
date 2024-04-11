#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3 + 1, B = 1e3 + 1, W = 12001;

int t, times[B], n, k, w[N], v[N], dp[N][W];

int main(){
	memset(times, 0x3f, sizeof(times));
	times[1] = 0;
	for(int i = 1; i < B; i++)
		for(int x = i; x >= 1 && i + i / x < B; x--)
			times[i + i / x] = min(times[i + i / x], times[i] + 1);
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++){
			scanf("%d", &w[i]);
			w[i] = times[w[i]];
		}
		for(int i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= min(W - 1, k); j++){
				dp[i][j] = dp[i - 1][j];
				if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		int ans = 0;
		for(int i = 0; i <= min(W - 1, k); i++)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}