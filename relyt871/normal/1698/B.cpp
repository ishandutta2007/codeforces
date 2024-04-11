#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

int n, k, a[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    if (k == 1) {
        printf("%d\n", (n - 1) / 2);
        return;
    }
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] > a[i - 1] + a[i + 1]) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}