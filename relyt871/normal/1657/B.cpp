#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n;
LL B, X, Y;

void solve() {
    read(n); read(B); read(X); read(Y);
    LL a = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a + X <= B) {
            a += X;
        } else {
            a -= Y;
        }
        ans += a;
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