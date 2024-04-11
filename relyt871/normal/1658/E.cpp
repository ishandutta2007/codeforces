#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 4005;
const int MAXV = 4000005;

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

int n, k, posx[MAXV], posy[MAXV], wincnt;
bool ans[MAXN][MAXN];

struct BIT {
    int tr[MAXN][MAXN];

    void add(int x, int y) {
        for (int i = x; i < MAXN; i += (i & (-i))) {
            for (int j = y; j < MAXN; j += (j & (-j))) {
                ++tr[i][j];
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i; i -= (i & (-i))) {
            for (int j = y; j; j -= (j & (-j))) {
                ret += tr[i][j];
            }
        }
        return ret;
    }

    int query(int xl, int xr, int yl, int yr) {
        if (xr >= MAXN) xr = MAXN - 1;
        if (yr >= MAXN) yr = MAXN - 1;
        int ret = sum(xr, yr);
        if (xl > 1) ret -= sum(xl - 1, yr);
        if (yl > 1) ret -= sum(xr, yl - 1);
        if (xl > 1 && yl > 1) ret += sum(xl - 1, yl - 1);
        return ret;
    }
} bit;

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; read(x);
            posx[x] = i;
            posy[x] = j;
        }
    }
    for (int i = n * n; i >= 1; --i) {
        int x = posx[i] + posy[i];
        int y = posx[i] - posy[i] + 2000;
        int cnt = bit.query(x - k, x + k, y - k, y + k);
        if (cnt == wincnt) {
            ++wincnt;
            bit.add(x, y);
            ans[posx[i]][posy[i]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            putchar((ans[i][j])? 'M' : 'G');
        }
        puts("");
    }
}

int main() {
    solve();
    return 0;
}