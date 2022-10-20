#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int n, x, a[MAXN];

void solve() {
    read(n); read(x);
    int mx = -1, mn = MAXN;
    LL base = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if (i > 1) {
            base += abs(a[i] - a[i - 1]);
        }
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    if (n > 1) {
        ans = (mn - 1) * 2;
        if (x > mx) {
            ans += (x - mx) * 2;
        }
    }
    LL tmp1 = 0, tmp2 = 0;
    if (mn > 1) {
        tmp1 += a[1] - 1;
        tmp2 += a[n] - 1;
    }
    if (x > mx) {
        tmp1 += x - a[n];
        tmp2 += x - a[1];
    }
    LL tmp3 = 0, tmp4 = 0;
    if (mn > 1) {
        tmp3 += (mn - 1) * 2;
        tmp4 += min(a[1] - 1, a[n] - 1);
    }
    if (x > mx) {
        tmp3 += min(x - a[1], x - a[n]);
        tmp4 += (x - mx) * 2;
    }
    LL tmp5 = 0x3f3f3f3f3f3f3f3f, tmp6 = 0x3f3f3f3f3f3f3f3f;
    if (mn > 1 && x > mx) {
        tmp5 = min(a[1] - 1 + x - 1, x - a[1] + x - 1);
        tmp6 = min(a[n] - 1 + x - 1, x - a[n] + x - 1);
    }
    printf("%lld\n", base + min(min(ans, min(tmp5, tmp6)), min(min(tmp1, tmp2), min(tmp3, tmp4))));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}