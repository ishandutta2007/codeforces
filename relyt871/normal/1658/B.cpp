#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;
const int MOD = 998244353;

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
    int n;
    read(n);
    if (n & 1) {
        puts("0");
    } else {
        int ans = 1;
        for (int i = 1; i <= n / 2; ++i) {
            ans = 1LL * ans * i % MOD;
        }
        ans = 1LL * ans * ans % MOD;
        printf("%d\n", ans);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}