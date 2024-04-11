#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 250005;

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

int n, a[MAXN], premx[MAXN], premn[MAXN], sufmx[MAXN], sufmn[MAXN];

inline int mn_cmp(int x, int y) {
    return (a[x] < a[y])? x : y;
}
inline int mx_cmp(int x, int y) {
    return (a[x] > a[y])? x : y;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    premx[1] = premn[1] = 1;
    for (int i = 2; i <= n; ++i) {
        premx[i] = mx_cmp(premx[i - 1], i);
        premn[i] = mn_cmp(premn[i - 1], i);
    }
    sufmx[n] = sufmn[n] = n;
    for (int i = n - 1; i >= 1; --i) {
        sufmx[i] = mx_cmp(sufmx[i + 1], i);
        sufmn[i] = mn_cmp(sufmn[i + 1], i);
    }
    int ans = 0;
    int p = premx[n], flag = 0;
    while (p != 1) {
        p = (flag? premx[p] : premn[p]);
        ++ans;
        flag ^= 1;
    }
    p = premx[n], flag = 0;
    while (p != n) {
        p = (flag? sufmx[p] : sufmn[p]);
        ++ans;
        flag ^= 1;
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