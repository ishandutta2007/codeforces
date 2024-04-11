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

void solve() {
    int n;
    read(n);
    printf("%d\n", (n - 6) / 3);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}