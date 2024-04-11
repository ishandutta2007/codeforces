#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define inf 2000000000

int n, k, s, t, c[N], v[N], g[N], d[N], ans, mn;

bool test(int v){
	long long sum = 0;
	for (int i = 0; i <= k; i ++) if (2ll * d[i] > v) sum += 2ll * d[i] - v;
	if (sum <= t - s) return 1;
	return 0;
}

void dac(int st, int en){
	if (st == en){
		mn = st;
		return;
	}
	int mid = (int)(1LL * en + st >> 1);
	if (test(mid)) dac(st, mid);
	else dac(mid + 1, en);
}

int main(){
	scanf("%d %d %d %d", &n, &k, &s, &t);
	ans = inf;
	for (int i = 0; i < n; i ++) scanf("%d %d", &c[i], &v[i]);
	for (int i = 1; i <= k; i ++) scanf("%d", &g[i]);
	sort(g + 1, g + k + 1);
	g[k + 1] = s;
	for (int i = 0; i <= k; i ++) d[i] = g[i + 1] - g[i];
	sort(d, d + k + 1);
	dac(d[k], inf);
	for (int i = 0; i < n; i ++) if (v[i] >= mn) if (ans > c[i]) ans = c[i];
	if (ans == inf)	printf("-1");
	else printf("%d", ans);
}