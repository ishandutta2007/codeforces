#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long calc(vector<int> &v) {
	if (v.empty()) return 0;
	vector<int> vv;
	for (int i: v) if (i & 1 ^ 1) vv.push_back(i >> 1);
	long long ans = vv.size() == v.size() ? 0 : quickpow(2, v.size() - 1);
	ans += calc(vv);
	return ans % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		v.push_back(p);
	}
	long long ans = quickpow(2, n) - 1;
	vector<int> vv;
	for (int i: v) if (i & 1 ^ 1) vv.push_back(i >> 1);
	ans -= calc(vv);
	ans = (ans % mod + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}