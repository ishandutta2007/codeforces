#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 205;
const int MAXN = 1000006;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, m;
char g[N][N];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", g[i] + 1);
    }
    if (g[1][1] == '1') {
        puts("-1");
        return;
    }
    printf("%d\n", n * m);
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (g[i][j] == '0') {
                printf("%d %d %d %d\n", i, j, i, j);
            } else {
                if (j > 1) {
                    printf("%d %d %d %d\n", i, j - 1, i, j);
                } else {
                    printf("%d %d %d %d\n", i - 1, j, i, j);
                }
            }
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}