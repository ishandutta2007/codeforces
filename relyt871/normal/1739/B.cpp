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

int n, d[105];

void solve() {
    read(n);
    int sum = 0, flag = 1;
    for (int i = 1; i <= n; ++i) {
        read(d[i]);
        if (d[i] && sum >= d[i]) {
            flag = 0;
        }
        sum += d[i];
    }
    if (flag) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", d[i] += d[i - 1]);
        }
        printf("\n");
    } else {
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