#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 305;

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

int n, a[N];

void solve() {
    read(n);
    printf("1\n");
    for (int i = 2; i <= n; ++i) {
        printf("1 ");
        for (int j = 2; j < i; ++j) {
            printf("0 ");
        }
        printf("1\n");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}