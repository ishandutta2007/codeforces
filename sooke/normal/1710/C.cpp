#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 2e5 + 5;

int ans, len, a[N], f[2][2][2][8][N];
std::string ns;



int main() {
    std::cin >> ns;
    len = ns.size();
    ns = " " + ns;
    for (int i = 1; i <= len; i++) {
        a[i] = ns[i] - '0';
    }
    f[0][0][0][0][0] = 1;
    for (int i = 1; i <= len; i++) {
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                for (int z = 0; z <= 1; z++) {
                    for (int o = 0; o <= (x ? 1 : a[i]); o++) { 
                        for (int p = 0; p <= (y ? 1 : a[i]); p++) {
                            for (int q = 0; q <= (z ? 1 : a[i]); q++) {
                                int t = 0;
                                int _x = x ? 1 : a[i] == 1 && o == 0 ? 1 : 0;
                                int _y = y ? 1 : a[i] == 1 && p == 0 ? 1 : 0;
                                int _z = z ? 1 : a[i] == 1 && q == 0 ? 1 : 0;
                                if ((o ^ p) == 0 && (o ^ q) == 1) { t |= 1; }
                                if ((o ^ p) == 1 && (o ^ q) == 0) { t |= 2; }
                                if ((o ^ p) == 1 && (o ^ q) == 1) { t |= 4; }
                                for (int s = 0; s < 8; s++) {
                                    f[_x][_y][_z][s | t][i] = add(f[_x][_y][_z][s | t][i], f[x][y][z][s][i - 1]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 1; y++) {
            for (int z = 0; z <= 1; z++) {
                ans = add(ans, f[x][y][z][7][len]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}