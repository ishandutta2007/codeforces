#include <cctype>
#include <cstdio>
#include <cstring>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }

const int N = 2005;

int n, ans, cnt[N], pwf[N], a[N][N], f[N][N];

struct FenwickTree {
    int f[N];

    void clear() { memset(f, 0, sizeof(int) * (n + 1)); }
    inline void modify(int u) { for (; u <= n; u += u & -u) { f[u]++; } }
    inline int query(int u) { int res = 0; for (; u; u ^= u & -u) { res += f[u]; } return res; }
} bit1, bit2;

int solve(int r) {
    int res = 0;
    if (r == 1) {
        for (int i = n; i; i--) {
            res = (1ll * f[n - i][0] * bit1.query(a[r][i]) + res) % mod;
            bit1.modify(a[r][i]);
        }
    } else {
        memset(cnt, 0, sizeof(int) * (n + 1)); bit1.clear(); bit2.clear();
        for (int i = n, j = 0, x, y; i; i--) {
            x = bit1.query(a[r][i]); y = bit2.query(a[r][i]); x -= y;
            if (a[r - 1][i] < a[r][i] && cnt[a[r - 1][i]] == 1) { x--; }
            if (cnt[a[r][i]] == 1) {
                res = (1ll * x * f[n - i][j + 1] + res) % mod;
                res = (1ll * y * f[n - i][j] + res) % mod;
            } else {
                res = (1ll * x * f[n - i][j] + res) % mod;
                if (y) { res = (1ll * y * f[n - i][j - 1] + res) % mod; }
            }
            bit1.modify(a[r][i]); cnt[a[r][i]]++; cnt[a[r - 1][i]]++;
            if (cnt[a[r][i]] == 2) { bit2.modify(a[r][i]); j++; }
            if (cnt[a[r - 1][i]] == 2) { bit2.modify(a[r - 1][i]); j++; }
        }
    }
    return res;
}

int main() {
    n = read(); f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1ll * f[i - 1][0] * i % mod;
        for (int j = 1; j <= n; j++) { a[i][j] = read(); f[i][j] = sub(f[i][j - 1], f[i - 1][j - 1]); }
    }
    for (int i = pwf[0] = 1; i <= n; i++) { pwf[i] = 1ll * pwf[i - 1] * f[n][n] % mod; }
    for (int i = 1; i <= n; i++) { ans = (1ll * solve(i) * pwf[n - i] + ans) % mod; }
    printf("%d\n", ans);
    return 0;
}