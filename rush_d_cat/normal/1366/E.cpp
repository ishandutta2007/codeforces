#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
typedef long long LL;
const LL MOD = 998244353;
int n, m;
int a[N], b[N], suf[N];
map<int, LL> mp;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &b[i]);
	}
	suf[n] = a[n];
	for (int i = n - 1; i >= 1; i --) {
		suf[i] = min(suf[i + 1], a[i]);
	}
	if (suf[1] != b[1]) return !printf("0\n");
	LL ans = 1;
	for (int i = 1; i <= n; i ++) {
		mp[suf[i]] ++;
	}
	for (int i = 2; i <= m; i ++) {
		ans = ans * mp[b[i]] % MOD;
	}
	printf("%lld\n", ans);
}