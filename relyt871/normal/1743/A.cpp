#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
    int n; read(n);
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
    }
    n = 10 - n;
    printf("%d\n", n * (n - 1) * 3);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}