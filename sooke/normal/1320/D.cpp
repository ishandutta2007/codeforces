#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, q, a[N], bl[N], br[N];
char s[N], t[N];

struct Hash {
    int base, mod, b[N], bi[N], f[N];

    int power(int x, int y, int p) {
        int res = 1;
        for (; y; y >>= 1, x = 1ll * x * x % p) {
            if (y & 1) { res = 1ll * res * x % p; }
        }
        return res;
    }

    void init(int _base, int _mod) {
        base = _base; mod = _mod; b[0] = 1; bi[0] = 1;
        for (int i = 1; i <= n; i++) {
            b[i] = 1ll * b[i - 1] * base % mod;
            bi[i] = power(b[i], mod - 2, mod);
        }
        for (int i = 1; i <= m; i++) {
            f[i] = (f[i - 1] + 1ll * b[i - 1] * (t[i] - 20ll)) % mod;
        }
    }

    int query(int l, int r) {
        return 1ll * ((f[r] + mod - f[l - 1]) % mod) * bi[l - 1] % mod;
    }

    int addl(int x, char c) {
        return (1ll * x * base + (c - 20)) % mod;
    }
    int addr(int x, int len, char c) {
        return (x + 1ll * b[len] * (c - 20ll)) % mod;
    }

    int solve(int l, int r) {
        int len;
        int x = br[l];
        int y = bl[r];
        if (x > y) {
            return r - l & 1 ? -1 : -2;
        } else if (x == y && t[x] == '1' && s[l] == ')') {
            return -1;
        } else if (x == y && t[x] == '1') {
            return -2;
        } else {
            int hsh;
            if (s[l] == ')' && t[x] == '1') {
                hsh = query(x + 1, y); len = y - x;
            } else {
                hsh = query(x, y); len = y - x + 1;
            }
            if (s[r] == '(') {
                hsh = addr(hsh, len, '1');
            }
            if (s[l] == ')' && t[x] == '0') {
                hsh = addl(hsh, '1');
            }
            return hsh;
        }
    }
} f, g;

int main() {
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1' && s[i] == '1') {
            s[i - 1] = '('; s[i] = ')';
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' || s[i] == '1') {
            t[++m] = s[i]; a[i] = m;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' || s[i] == '1') {
            bl[i] = a[i];
        } else {
            bl[i] = bl[i - 1];
        }
    }
    br[n + 1] = m + 1;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0' || s[i] == '1') {
            br[i] = a[i];
        } else {
            br[i] = br[i + 1];
        }
    }
    f.init(131, 998244353);
    g.init(133, 998244853);
    q = read();
    for (int i = 0; i < q; i++) {
        int l = read(), r = read(), len = read();
        if (f.solve(l, l + len - 1) == f.solve(r, r + len - 1) && g.solve(l, l + len - 1) == g.solve(r, r + len - 1)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}