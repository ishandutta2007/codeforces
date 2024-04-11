#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

int n, h[MAXN], mx, to;

bool Check(LL mid) {
    LL one = (mid + 1) / 2, two = mid / 2;
    for (int i = 1; i <= n; ++i) {
        LL delta = to - h[i];
        LL use = min(two, delta / 2);
        two -= use;
        delta -= use * 2;
        one -= delta;
    }
    return (one >= 0 && two >= 0);
}

void solve() {
    read(n);
    mx = 0;
    for (int i = 1; i <= n; ++i) {
        read(h[i]);
        mx = max(mx, h[i]);
    }
    LL worst = 0;
    for (int i = 1; i <= n; ++i) {
        worst += mx - h[i];
    }
    LL ans = worst * 2;
    for (to = mx; to <= mx + 1; ++to) {
        LL L = 0, R = worst * 2;
        while (L <= R) {
            LL mid = (L + R) >> 1;
            if (Check(mid)) {
                ans = min(ans, mid);
                R = mid - 1;
            } else {
                L = mid + 1;
            }
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