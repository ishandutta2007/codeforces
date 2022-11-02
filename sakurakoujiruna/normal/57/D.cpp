#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
using ll = long long;

char s[N][N];
int cnt_x[N], cnt_y[N];

int a[N];
ll solve(int n, int m) {
	ll ret = 0;
	for(int x = 1; x <= n; x ++) if(a[x]) {
		ret += (a[x] - 1) * (m - a[x]);
		for(int i = x + 1; i <= n; i ++) {
			if(!a[i] || a[i] < a[i - 1]) break;
			ret += 2 * (a[x] - 1) * (m - a[i]);
		}
	}
	return ret * 2;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	int dyns = 0;
	for(int x = 1; x <= n; x ++)
		for(int y = 1; y <= m; y ++)
			if(s[x][y] == '.') {
				cnt_x[x] ++;
				cnt_y[y] ++;
				dyns ++;
			}

	ll ans = 0;
	for(int x = 1; x <= n; x ++) {
		for(int i = 1; i < x; i ++)
			ans += ll(x - i) * cnt_x[x] * cnt_x[i];
		for(int i = x + 1; i <= n; i ++)
			ans += ll(i - x) * cnt_x[x] * cnt_x[i];
	}
	for(int y = 1; y <= m; y ++) {
		for(int i = 1; i < y; i ++)
			ans += ll(y - i) * cnt_y[y] * cnt_y[i];
		for(int i = y + 1; i <= m; i ++)
			ans += ll(i - y) * cnt_y[y] * cnt_y[i];
	}
	for(int x = 1; x <= n; x ++)
		for(int y = 1; y <= m; y ++)
			if(s[x][y] == 'X') a[x] = y;
	ans += solve(n, m);
	for(int x = 1; x <= n; x ++)
		if(a[x]) a[x] = m - a[x] + 1;
	ans += solve(n, m);

	memset(a, 0, sizeof(a));
	for(int x = 1; x <= n; x ++)
		for(int y = 1; y <= m; y ++)
			if(s[x][y] == 'X') a[y] = x;
	ans += solve(m, n);
	for(int y = 1; y <= m; y ++)
		if(a[y]) a[y] = n - a[y] + 1;
	ans += solve(m, n);
	ll pairs = ll(dyns) * dyns;
	printf("%.9f\n", (double)ans / pairs);
	return 0;
}