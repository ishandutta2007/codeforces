#include <bits/stdc++.h>
using namespace std;
const int N = 8002;
int t, n, a[N], sum[N];
bool vis[8002];
int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		memset(vis,0,sizeof(vis));
		for (int i = 2; i <= n; i ++) {
			for (int j = 0; j <= i - 2; j ++) {
				if (sum[i] - sum[j] <= n)
					vis[sum[i] - sum[j]] = 1;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[a[i]]) ans ++;
		}
		printf("%d\n", ans);
	}
}