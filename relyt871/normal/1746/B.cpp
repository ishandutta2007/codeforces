#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;

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

int n, a[MAXN], cnt[2][MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        cnt[0][i] = cnt[0][i - 1] + (a[i] == 0);
        cnt[1][i] = cnt[1][i - 1] + (a[i] == 1);
    }
    if (n == 1) {
        printf("0\n");
        return;
    }
    int ans = n;
    for (int i = 0; i <= n; ++i) {
        if (cnt[1][i] >= cnt[0][n] - cnt[0][i]) {
            ans = min(ans, cnt[1][i]);
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