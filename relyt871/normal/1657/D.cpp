#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXC = 1000006;

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

inline void cmax(LL &x, LL y) {
    if (x < y) x = y;
}

int n, C, q;
LL mxd[MAXC];

void solve() {
    read(n); read(C);
    for (int i = 1; i <= n; ++i) {
        int c, d, h;
        read(c); read(d); read(h);
        cmax(mxd[c], 1LL * d * h);
    }
    for (int i = 1; i <= C; ++i) {
        for (int j = 2; i * j <= C; ++j) {
            cmax(mxd[i * j], mxd[i] * j);
        }
        cmax(mxd[i], mxd[i - 1]);
    }

    read(q);
    while (q--) {
        LL D, H;
        read(D); read(H);
        int p = upper_bound(mxd + 1, mxd + C + 1, D * H) - mxd;
        printf("%d ", (p > C)? -1 : p);
    }
}

int main() {
    solve();
    return 0;
}