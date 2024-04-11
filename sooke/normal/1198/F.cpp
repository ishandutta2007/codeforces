#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, gcd, a[N], b[N], e[N], ans[N], ord[N], cnt[N];
clock_t st = clock();

bool solve() {
    for (int i = 0; i < m; i++) { ord[i] = i; }
    while (true) {
        if (clock() - st >= 460) { break; }
        gcd = 0;
        for (int i = 0; i < m; i++) { e[i] = b[ord[i]]; }
        for (int i = 0; i < m - 1; i++) {
            gcd = std::__gcd(gcd, e[i]);
            if (gcd == 1) {
                gcd = 0;
                for (int j = i + 1; j < m; j++) {
                    gcd = std::__gcd(gcd, e[j]);
                    if (gcd == 1) {
                        for (int k = 0; k <= i; k++) { ans[ord[k]] = 1; }
                        for (int k = m - 1; k > i; k--) { ans[ord[k]] = 2; }
                        return true;
                    }
                }
            }
        }
        std::random_shuffle(ord, ord + m);
    }
    return false;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = b[i] = read(); }
    std::sort(b, b + n);
    m = std::unique(b, b + n) - b;
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(b, b + m, a[i]) - b; cnt[a[i]]++;
    }
    int _m = m;
    for (int i = 0; i < _m; i++) {
        if (cnt[i] >= 2) { b[m++] = b[i]; }
    }
    std::sort(b + _m, b + m);
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] >= 2) {
            cnt[a[i]]--; a[i] = std::lower_bound(b + _m, b + m, b[a[i]]) - b;
        } else { cnt[a[i]]--; }
    }
    if (solve()) {
        printf("YES\n");
        for (int i = 0; i < n; i++) { printf("%d ", ans[a[i]]); }
    } else { printf("NO\n"); }
    return 0;
}