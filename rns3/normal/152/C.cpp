#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

#define N 110

char a[N][N];
int n, m, vis[30];
long long ans = 1, tag;

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i ++) gets(a[i]);
	for (int j = 0; j < m; j ++) {
		memset(vis, 0, sizeof vis);
		tag = 0;
		for (int i = 1; i <= n; i ++) {
			vis[a[i][j]-'A'] = 1;
		}
		for (int i = 0; i <= 25; i ++) if (vis[i]) tag ++;
		ans = (ans * tag) % P;
	}
	printf("%d\n", ans);
	return 0;
}