#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rd() {
	ll x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 110;
ll a[N], p[N];
int n;
bool f, v[N];

void dfs(int x, int y) {
	if (y == n && !f) {
		f = 1;
		for (int i = 1; i <= n; i ++) printf("%lld ", p[i]);
		return;
	}
	v[x] = 1;
	for (int i = 1; i <= n; i ++) {
		if (v[i]) continue;
		if (p[y] * 2 == a[i] || p[y] == a[i] * 3) {
			p[y + 1] = a[i];
			dfs(i, y + 1);
		}
	}
	v[x] = 0;
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 1; i <= n; i ++) {
		memset(v, 0, sizeof v);
		p[1] = a[i];
		dfs(i, 1);
		if (f) return 0;
	}
	return 0;
}