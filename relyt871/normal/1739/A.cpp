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

void solve() {
    int n, m;
    read(n); read(m);
    if (n == 1 || m == 1) {
        printf("1 1\n");
    } else {
        printf("2 2\n");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}