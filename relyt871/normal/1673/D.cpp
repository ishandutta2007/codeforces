#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

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

LL b, db, lb, c, dc, lc;
LL ans;

inline LL lcm(LL x, LL y) {
    return x / __gcd(x, y) * y;
}

void Check(LL da) {
    if (lcm(da, db) == dc) {
        ans = (ans + (dc / da) * (dc / da)) % MOD;
    }
}

void solve() {
    read(b); read(db); read(lb);
    read(c); read(dc); read(lc);
    if (c < b || c + dc * (lc - 1) > b + db * (lb - 1)) {
        puts("0");
        return;
    }
    if (dc % db || (c - b) % db) {
        puts("0");
        return;
    }
    int flag = 0;
    flag += (c + dc * lc <= b + db * (lb - 1));
    flag += (c - dc >= b);
    if (flag < 2) {
        puts("-1");
        return;
    }
    ans = 0;
    for (LL i = 1; i * i <= dc; ++i) {
        if (dc % i) continue;
        Check(i);
        if (i * i != dc) {
            Check(dc / i);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}