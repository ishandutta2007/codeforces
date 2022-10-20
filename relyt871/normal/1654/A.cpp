#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n, a[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    printf("%d\n", a[n] + a[n - 1]);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}