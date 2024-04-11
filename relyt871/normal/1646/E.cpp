#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int n, m, ispw[MAXN];
bool vis[20000005];
int cnt[30];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= 20; ++i) {
        cnt[i] = cnt[i - 1];
        for (int j = 1, k = i; j <= m; ++j, k += i) {
            if (!vis[k]) {
                ++cnt[i];
                vis[k] = 1;
            }
        }
    }
    LL ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (ispw[i]) continue;
        int mx = 0;
        for (LL j = i; j <= n; j *= i) {
            ispw[j] = 1;
            ++mx;
        }
        ans += cnt[mx];
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}