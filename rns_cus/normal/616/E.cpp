#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, m, ans;
const LL mod = 1000000007;

LL calc(LL st, LL en, LL a) {
	LL rlt = (en - st + 1) % mod * ((n * 2 - a * st - a * en) % mod) % mod;
	if (rlt % 2 == 0) return rlt / 2;
	else return (rlt + mod) / 2;
}

int main() {
//	freopen("e.in", "r", stdin);
	cin >> n >> m;
	if (m > n) {
		ans = (n % mod) * ((m - n) % mod) % mod;
	}
	LL st = m + 1, en;
	LL End = sqrt(n);
	for (int a = 1; a <= End; a ++) {
        st = n / (a + 1) + 1, en = n / a;
        if (st > m) continue;
        if (en > m) en = m;
        ans = (ans + calc(st, en, a)) % mod;
	}
	st = min(st, m + 1);
	for (int i = 1; i < st; i ++) ans = (ans + n % i) % mod;
	cout << ans << endl;
	return 0;
}