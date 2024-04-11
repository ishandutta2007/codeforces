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

inline void cmax(int &x, int y) {
    if (x < y) x = y;
}

int n, m, ans;
LL a[MAXN], b[MAXN];

void Check1(LL d) {
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - d * (i - 1);
    }
    sort(b + 1, b + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || b[i] == b[i - 1]) {
            ++cnt;
        } else {
            cmax(ans, cnt);
            cnt = 1;
        }
    }
    cmax(ans, cnt);
}

void Check2(int s) {
    int tot = 0;
    for (int i = s + 1; i <= s + m && i <= n; ++i) {
        if ((a[i] - a[s]) % (i - s)) continue;
        b[++tot] = (a[i] - a[s]) / (i - s);
    }
    sort(b + 1, b + tot + 1);
    int cnt = 0;
    for (int i = 1; i <= tot; ++i) {
        if (i == 1 || b[i] == b[i - 1]) {
            ++cnt;
        } else {
            cmax(ans, cnt + 1);
            cnt = 1;
        }
    }
    cmax(ans, cnt + 1);
}

void solve() {
    read(n);
    if (n == 1) {
        printf("0\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    m = min(n, 320);
    ans = 2;
    for(int d = -m; d <= m; ++d) {
        Check1(d);
    }
    for (int i = 1; i <= n; ++i) {
        Check2(i);
    }
    printf("%d\n", n - ans);
}

int main() {
    solve();
    return 0;
}