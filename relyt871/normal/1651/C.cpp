#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 1000005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

int n;
LL a[MAXN], b[MAXN];

inline LL Find(LL x, LL *c) {
    LL ret = INF;
    for (int i = 1; i <= n; ++i) {
        ret = min(ret, llabs(x - c[i]));
    }
    return ret;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    LL a1 = Find(a[1], b), an = Find(a[n], b);
    LL b1 = Find(b[1], a), bn = Find(b[n], a);
    LL ans = a1 + an + b1 + bn;
    ans = min(ans, llabs(a[1] - b[1]) + llabs(a[n] - b[n]));
    ans = min(ans, llabs(a[1] - b[n]) + llabs(a[n] - b[1]));
    ans = min(ans, llabs(a[1] - b[1]) + an + bn);
    ans = min(ans, llabs(a[1] - b[n]) + an + b1);
    ans = min(ans, llabs(a[n] - b[1]) + a1 + bn);
    ans = min(ans, llabs(a[n] - b[n]) + a1 + b1);
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}