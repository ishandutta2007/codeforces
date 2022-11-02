#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
const int Inf = 0x7f7f7f7f;
using ll = long long;
int c[N], v[N];
int g[N];

int solve(ll v, int n) {
	int p = 0, ret = 0;
	for(int i = 0; i < n; i ++) {
		if(g[i] - p > v) return Inf;
		else if((g[i] - p) * 2 <= v)
			ret += g[i] - p;
		else
			ret += 3LL * (g[i] - p) - v;
		p = g[i];
	}
	return ret;
}

int main() {
	int n, k, s, t; scanf("%d%d%d%d", &n, &k, &s, &t);
	for(int i = 0; i < n; i ++)
		scanf("%d%d", c + i, v + i);
	for(int i = 0; i < k; i ++)
		scanf("%d", g + i);
	g[k ++] = s;
	sort(g, g + k);

	ll left = 0, right = Inf;
	while(left + 1 < right) {
		ll mid = (left + right) / 2;
		if(solve(mid - 1, k) <= t)
			right = mid;
		else
			left = mid;
	}
	int ans = Inf;
	for(int i = 0; i < n; i ++)
		if(v[i] >= left) ans = min(ans, c[i]);
	cout << (ans == Inf ? -1 : ans) << '\n';
	return 0;
}