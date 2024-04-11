#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

void solve() {
    LL n; read(n);
    if (n & 1) {
        puts("2");
    } else {
        LL tmp = n;
        while (tmp % 2 == 0) {
            tmp /= 2;
        }
        if (tmp != 1 && tmp <= 2e9 && tmp * (tmp + 1) / 2 <= n) {
            printf("%lld\n", tmp);
            return;
        }
        tmp = n / tmp * 2;
        if (tmp != 1 && tmp <= 2e9 && tmp * (tmp + 1) / 2 <= n) {
            printf("%lld\n", tmp);
            return;
        }
        puts("-1");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}