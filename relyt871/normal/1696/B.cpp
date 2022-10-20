#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
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
    int n; read(n);
    int lst = 0, cnt = 0;
    bool all0 = 1, allnot0 = 1;
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        if (x) all0 = 0;
        else allnot0 = 0;
        if (!x) {
            if (lst != i - 1) {
                ++cnt;
            }
            lst = i;
        }
    }
    if (lst != n) ++cnt;
    if (all0) {
        printf("0\n");
    } else if (allnot0 || cnt == 1) {
        printf("1\n");
    } else {
        printf("2\n");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}