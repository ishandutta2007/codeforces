#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizoef(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

int n, a[MAXN];

void solve() {
    read(n);
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        if (i > 1 && a[i] < a[i - 1]) {
            flag = 0;
        }
    }
    puts(flag? "NO" : "YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}