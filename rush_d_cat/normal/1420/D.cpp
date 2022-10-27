#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 600000 + 10;
const LL MOD = 998244353;

int n, k;
pair<int, int> p[N];
multiset< pair<int,int> > st;

LL fac[N], inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL C(int x, int y) {
	return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
}
int main() {
	fac[0] = inv[0] = 1;

	for (int i = 1; i < N; i ++) {
		fac[i] = fac[i-1] * i % MOD; inv[i] = mpow(fac[i], MOD - 2);
	}
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	} 
	sort(p + 1, p + 1 + n);
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		while (st.size()) {
			auto it = st.begin();
			if ((*it).first < p[i].first) {
				st.erase(st.begin());
			} else break;
		}
		int cnt = st.size();
		// printf("i = %d, cnt = %d\n", i, cnt);
		if (cnt >= k - 1) ans += C(cnt, k - 1);
		ans %= MOD;
		st.insert(make_pair(p[i].second, p[i].first));
	}
	cout << ans << endl;
}