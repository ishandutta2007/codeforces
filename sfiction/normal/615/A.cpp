#include <cstdio>

const int MAXM = 1E2 + 10;

int vis[MAXM];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		vis[i] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j){
			int t;
			scanf("%d", &t);
			ans += !vis[t];
			vis[t] = 1;
		}
	}
	puts(ans == m ? "YES" : "NO");
	return 0;
}