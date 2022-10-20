#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 105;

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

int n, a[MAXN], b[MAXN];

void solve() {
    int n; read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int dif = 0, c0 = 0, c1 = 0;
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        if (a[i] != b[i]) {
            ++dif;
            c0 += (a[i] == 0);
            c1 += (a[i] == 1);
        }
    }
    printf("%d\n", min(dif, abs(c0 - c1) + 1));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}