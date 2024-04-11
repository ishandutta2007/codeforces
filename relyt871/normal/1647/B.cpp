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
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1] == 195) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}