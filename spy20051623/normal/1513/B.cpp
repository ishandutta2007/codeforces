#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long p[200005];

map<int, int> m;

void solve() {
	m.clear();
	int n, s, b;
	scanf("%d", &n);
	scanf("%d", &b);
	++m[b];
	for (int i = 1; i < n; ++i) {
		scanf("%d", &s);
		b &= s;
		++m[s];
	}
	long long res;
	res = 1LL * m[b] * (m[b] - 1);
	res %= mod;
	res *= p[n - 2];
	res %= mod;
	printf("%d\n", res);
}

int main() {
//	freopen("in.txt", "r", stdin);
	p[0] = 1;
	for (int i = 1; i <= 200000; ++i) {
		p[i] = p[i - 1] * i % mod;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}