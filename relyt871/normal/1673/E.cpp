#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = (1 << 20) + 5;
const int MOD = (1 << 20);

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

int n, K, b[MAXN];
int ans[MAXN];
int f[MAXN];

inline int C(int x, int y) {
    return ((x & y) == y);
}

inline int Calc(int x, int y) {
    x -= y;
    int ret = f[x];
    if (y >= 1) {
        if (K >= 1) ret ^= C(x, K - 1);
    }
    if (y >= 2) {
        if (K >= 2) ret ^= C(x, K - 2);
    }
    return ret;
}

void solve() {
    read(n); read(K);
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    for (int i = 0; i < K; ++i) {
        f[i] = 1;
    }
    for (int i = 1; i < MOD; i <<= 1) {
        for (int j = 0; j < MOD; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                f[j + k + i] ^= f[j + k];
            }
        }
    }
    f[0] ^= 1;
    for (int i = 1; i <= n; ++i) {
        LL pw = 1;
        for (int j = i; j <= n; ++j) {
            if (j == i) {
                pw = b[i];
            } else if (b[j] >= 20) {
                break;
            } else {
                pw *= (1 << b[j]);
            }
            if (pw >= MOD) break;
            int blank = i - 1 + n - j;
            int flag = (i > 1) + (j < n);
            if (blank >= K) {
                ans[pw] ^= Calc(blank, flag);
            }
        }
    }
    int p = MOD - 1;
    while (p >= 0 && !ans[p]) --p;
    for (int i = max(0, p); i >= 0; --i) {
        putchar('0' + ans[i]);
    }
}

int main() {
    solve();
    return 0;
}