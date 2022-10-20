#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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
LL C[70][70];

void solve() {
    read(n);
    LL win = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 4 == 2) {
            win += C[n - i + 1][n / 2 - i / 2];
        } else if (i % 4 == 0 && i / 2 + 1 <= n / 2) {
            win += C[n - i][n / 2 - i / 2 - 1];
        }
    }
    LL lose = C[n][n / 2] - win - 1;
    printf("%d %d 1\n", win % 998244353, lose % 998244353);
}

int main() {
    for (int i = 0; i <= 60; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}