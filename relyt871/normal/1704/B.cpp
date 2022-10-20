#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
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

int n, x, a[MAXN];

void solve() {
    read(n); read(x);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int cnt = 0, mn = a[1], mx = a[1];
    for (int i = 2; i <= n; ++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (mx - mn > x * 2) {
            ++cnt;
            mn = mx = a[i];
        }
    }
    printf("%d\n", cnt);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}