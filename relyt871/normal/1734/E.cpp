#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

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
    for (int i = 0; i < n; ++i) {
        int b; read(b);
        for (int j = 0; j < n; ++j) {
            printf("%d ", (i * ((j + n - i) % n) + b) % n);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}