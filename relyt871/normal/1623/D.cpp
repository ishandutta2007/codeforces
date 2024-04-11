#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

namespace ModCalculator {
    const int MOD = 1e9 + 7;
	inline void Inc(int &x, int y) {
		x += y; if (x >= MOD) x -= MOD;
	}
	inline void Dec(int &x, int y) {
		x -= y; if (x < 0) x += MOD;
	}
	inline int Add(int x, int y) {
		Inc(x, y); return x;
	}
	inline int Sub(int x, int y) {
		Dec(x, y); return x;
	}
	inline int Mul(int x, int y) {
		return 1LL * x * y % MOD;
	}
	inline int Ksm(int x, int y) {
		int ret = 1;
		for (; y; y >>= 1) {
			if (y & 1) ret = Mul(ret, x);
			x = Mul(x, x);
		}
		return ret;
	}
	inline int Inv(int x) {
		return Ksm(x, MOD - 2);
	}
}
using namespace ModCalculator;

int n, m, p, q;
int rb, cb, rd, cd;
set<LL> S;

void solve() {
    read(n); read(m);
    read(rb); read(cb); read(rd); read(cd);
    read(p);
    p = Mul(p, Inv(100));
    q = Sub(1, p);
    LL rt1, rt2;
    if (rd >= rb) {
        rt1 = rd - rb;
        rt2 = (n - rd) * 2;
    } else {
        rt1 = n * 2 - rb - rd;
        rt2 = (rd - 1) * 2;
    }
    if (rd == 1 || rd == n) rt2 = 0;
    LL ct1, ct2;
    if (cd >= cb) {
        ct1 = cd - cb;
        ct2 = (m - cd) * 2;
    } else {
        ct1 = m * 2 - cd - cb;
        ct2 = (cd - 1) * 2;
    }
    if (cd == 1 || cd == m) ct2 = 0;
    LL lim = 2 * (n - 1) * (m - 1) / __gcd(n - 1, m - 1);
    S.clear();
    while (rt1 < lim) {
        S.insert(rt1);
        if (rt2) S.insert(rt1 + rt2);
        rt1 += 2 * (n - 1);
    }
    while (ct1 < lim) {
        S.insert(ct1);
        if (ct2) S.insert(ct1 + ct2);
        ct1 += 2 * (m - 1);
    }
    int qk = Ksm(q, S.size()), iqk = Inv(Sub(1, qk)), val = Mul(qk, iqk);
    int ans = 0, pre = 1, tmp = lim % MOD;
    for (auto x : S) {
        int t = x % MOD;
        int cur = Add(t, Mul(tmp, val));
        Inc(ans, Mul(pre, cur));
        pre = Mul(pre, q);
    }
    ans = Mul(ans, Mul(p, iqk));
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}