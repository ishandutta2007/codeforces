#include <bits/stdc++.h>
using namespace std;

#define N 303

int n, x[N], y[N];
int cost[N];
int val[N];

map <string, int> mp;
string s;

map <pair <int, int>, int> go;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	//freopen("r.in", "r", stdin);
	int a, b, k, f;
	scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
	int m = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		if (!mp.count(s)) mp[s] = ++m;
		x[i] = mp[s];
		cin >> s;
		if (!mp.count(s)) mp[s] = ++m;
		y[i] = mp[s];
	}
	for (int i = 1; i <= n; i ++) {
		if (i > 1 && y[i-1] == x[i]) cost[i] = b;
		else cost[i] = a;
	}//for (int i = 1; i <= n; i ++) printf("%d ", cost[i]);puts("");
	m = 0;
	for (int i = 1; i <= n; i ++) {
		if (x[i] > y[i]) swap(x[i], y[i]);
		if (!go.count(make_pair(x[i], y[i]))) go[make_pair(x[i], y[i])] = ++m;
		val[go[make_pair(x[i], y[i])]] += cost[i];
	}
	sort(val + 1, val + m + 1, cmp);
	for (int i = 1; i <= min(m, k); i ++) {
		if (val[i] <= f) break;
		else val[i] = f;
	}
	long long ans = 0;
	for (int i = 1; i <= m; i ++) ans += val[i];
	printf("%I64d\n", ans);

	return 0;
}