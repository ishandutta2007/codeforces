#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
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

int n, m, a[MAXN], b[MAXN], tot;

void solve() {
    read(n); read(m);
    for (int i = 1; i <= m; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + m + 1);
    tot = 0;
    for (int i = 2; i <= m; ++i) {
        if (a[i - 1] + 1 != a[i]) {
            b[++tot] = a[i] - a[i - 1] - 1;
        }
    }
    if (m != 1 && (a[1] != 1 || a[m] != 1)) {
        b[++tot] = n + a[1] - a[m] - 1;
    }
    if (m == 1) {
        b[++tot] = n - 1;
    }
    sort(b + 1, b + tot + 1);
    int ans = 0, days = 0;
    for (int i = tot; i >= 1; --i) {
        if (b[i] <= days * 2) break;
        b[i] -= days * 2;
        if (b[i] <= 2) {
            ++ans;
            ++days;
        } else {
            ans += b[i] - 1;
            days += 2;
        }
    }
    printf("%d\n", n - ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}