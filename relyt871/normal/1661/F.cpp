#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, a[MAXN];
LL m, my, need, mid;

inline LL Sqr(LL x) {
    return x * x;
}

inline LL Cost(LL len, LL c) {
    LL x = len / c, r = len - x * c;
    return Sqr(x + 1) * r + Sqr(x) * (c - r);
}

inline LL Count(LL len) {
    LL L = 1, R = len - 1, ret = len;
    while (L <= R) {
        LL M = (L + R) >> 1;
        if (Cost(len, M) - Cost(len, M + 1) < mid) {
            ret = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    return ret;
}

bool Check() {
    need = my = 0;
    for (int i = 1; i <= n; ++i) {
        LL c = Count(a[i]);
        need += c - 1;
        my += Cost(a[i], c);
    }
    return (my <= m);
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    read(m);
    for (int i = n; i >= 1; --i) {
        a[i] -= a[i - 1];
    }
    LL L = 0, R = 1e18, P = 1e9;
//mid = 1; Check();
    while (L <= R) {
        mid = (L + R) >> 1;
        if (Check()) {
            P = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    mid = P;
    Check();
    printf("%lld\n", need - (m - my) / P);
}

int main() {
    solve();
    return 0;
}