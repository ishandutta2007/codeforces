#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int power(int x, long long y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long g = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
long long get(long long x, long long d) {
    return x >= 0 ? x / d : -((-1 - x) / d + 1);
}
long long module(long long x, long long d) {
    return x - d * get(x, d);
}

const int N = 1e2 + 5, M = 2e3 + 5;

int n, m, _a[N], _b[N], pri[M], a[N][M], b[N][M];
long long ai[M], bi[M], aj[M], bj[M], gcd[M];
long long kx[M], ky[M], dx[M], dy[M], ans[M], sol[N];

void depose(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            pri[m++] = d;
            while (x % d == 0) {
                x /= d;
            }
        }
    }
    if (x > 1) { pri[m++] = x; }
}
void degrade(int x, int a[]) {
    for (int i = 0; i < m; i++) {
        while (x % pri[i] == 0) {
            x /= pri[i]; a[i]++;
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        sol[i] = -1;
        for (int d = 0; d < m; d++) {
            long long tmp = ans[d] - a[i][d];
            if (tmp == 0 && b[i][d] == 0) { continue; }
            if (tmp < 0 || b[i][d] == 0 || tmp % b[i][d] != 0) {
                printf("-1\n"); exit(0);
            }
            if (sol[i] == -1) {
                sol[i] = tmp / b[i][d];
            } else {
                if (sol[i] != tmp / b[i][d]) {
                    printf("-1\n"); exit(0);
                }
            }
        }
    }
    long long res = 1;
    for (int i = 0; i < m; i++) {
        res = 1ll * res * power(pri[i], ans[i]) % mod;
    }
    printf("%lld\n", res); exit(0);
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        _a[i] = read(); _b[i] = read();
        depose(_a[i]); depose(_b[i]);
    }
    std::sort(pri, pri + m);
    m = std::unique(pri, pri + m) - pri;
    for (int i = 0; i < n; i++) {
        degrade(_a[i], a[i]); degrade(_b[i], b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int d = 0; d < m; d++) {
            ai[d] = a[i][d]; bi[d] = b[i][d];
        }
        if (i > 0) {
            for (int d = 0; d < m; d++) {
                if (bi[d] == 0 && bj[d] == 0) {
                    if (ai[d] != aj[d]) {
                        printf("-1\n"); exit(0);
                    }
                    gcd[d] = 1;
                    kx[d] = 0; dx[d] = 0;
                    ky[d] = 0; dy[d] = 0;
                    continue;
                }
                long long x, y, _x, _y, g = gcd[d] = exgcd(bi[d], bj[d], x, y);
                if ((aj[d] - ai[d]) % g != 0) {
                    printf("-1\n"); exit(0);
                }
                kx[d] = 0; dx[d] = bj[d] / g;
                ky[d] = 0; dy[d] = bi[d] / g;
                _y = bi[d] == 0 ? (ai[d] - aj[d]) / g : module(y * module((ai[d] - aj[d]) / g, dy[d]), dy[d]);
                _x = bi[d] == 0 ? 0 : (aj[d] - ai[d] + _y * bj[d]) / bi[d];
                if (dx[d] != 0) {
                    kx[d] = std::max(kx[d], _x - dx[d] * get(_x, dx[d]));
                    ky[d] = std::max(ky[d], _y - dy[d] * get(_x, dx[d]));
                }
                if (dy[d] != 0) {
                    kx[d] = std::max(kx[d], _x - dx[d] * get(_y, dy[d]));
                    ky[d] = std::max(ky[d], _y - dy[d] * get(_y, dy[d]));
                }
            }
            long long x = 0, y = 0, p, q;
            for (int d = 0; d < m; d++) {
                if (dx[d] == 0 && dy[d] == 0) { continue; }
                if (x == 0 && y == 0) {
                    p = kx[d]; q = ky[d];
                    x = dx[d]; y = dy[d];
                    continue;
                }
                if (x != dx[d] || y != dy[d]) {
                    long long k = ((ky[d] - q) * dx[d] - (kx[d] - p) * dy[d]) / (y * dx[d] - x * dy[d]);
                    k = p + x * k;
                    for (int d = 0; d < m; d++) {
                        ans[d] = ai[d] + bi[d] * k;
                    }   
                    print();
                }
            }
        }
        long long max = *std::max_element(kx, kx + m);
        for (int d = 0; d < m; d++) {
            if (i == 0) {
                aj[d] = ai[d]; bj[d] = bi[d];
                continue;
            }
            aj[d] = ai[d] + bi[d] * max;
            bj[d] = bi[d] / gcd[d] * bj[d];
        }
    }
    for (int i = 0; i < m; i++) {
        ans[i] = aj[i];
    }
    print();
    return 0;
}