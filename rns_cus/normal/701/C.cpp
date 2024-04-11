#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define M 55
#define inf 1e9

int n, m, a[N], last[N][M];
char s[N];
map <char, int> mp;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %s", &n, s);
	for (int i = 0; i < n; i ++) {
		if (!mp[s[i]]) mp[s[i]] = ++m;
		a[i+1] = mp[s[i]];
	}
    for (int i = 1; i <= m; i ++) last[n+1][i] = inf;
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; j ++) last[i][j] = last[i+1][j];
		last[i][a[i]] = i;
	}
	int ans = n;
	for (int i = 1; i <= n; i ++) {
		int rlt = 0;
		for (int j = 1; j <= m; j ++) rlt = max(rlt, last[i][j]);
		ans = min(ans, rlt - i + 1);
	}
	printf("%d\n", ans);
	return 0;
}