#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 17) + 5;
const int MOD = 998244353;

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

int n, l, r, a[MAXN];
int tot, root, ch[MAXN * 20][2];

void Insert(int &rt, int x, int d) {
    if (!rt) {
        rt = ++tot;
        ch[rt][0] = ch[rt][1] = 0;
    }
    if (d < 0) return;
    Insert(ch[rt][(x >> d) & 1], x, d - 1);
}

int QueryMin(int rt, int x, int d) {
    if (d < 0) return 0;
    int t = ((x >> d) & 1);
    if (ch[rt][t]) {
        return QueryMin(ch[rt][t], x, d - 1);
    } else {
        return QueryMin(ch[rt][t ^ 1], x, d - 1) + (1 << d);
    }
}

int QueryMax(int rt, int x, int d) {
    if (d < 0) return 0;
    int t = ((x >> d) & 1);
    if (ch[rt][t ^ 1]) {
        return QueryMax(ch[rt][t ^ 1], x, d - 1) + (1 << d);
    } else {
        return QueryMax(ch[rt][t], x, d - 1);
    }
}

void solve() {
    read(l); read(r);
    n = r - l + 1;
    tot = root = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        Insert(root, a[i], 16);
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i] ^ l;
        if (QueryMin(root, x, 16) == l && QueryMax(root, x, 16) == r) {
            printf("%d\n", x);
            return;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}