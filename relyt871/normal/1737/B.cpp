#include <bits/stdc++.h>
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

LL Calc(LL x) {
    if (x == 0) return 0;
    LL y = sqrt(x), ret = 0;
    while (y * (y + 2) > x) {
        ret += (y * y <= x) + (y * y + y <= x);
        --y;
    }
    ret += y * 3;
    return ret;
}

void solve() {
    LL l, r;
    read(l); read(r);
    printf("%lld\n", Calc(r) - Calc(l - 1));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}