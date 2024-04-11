#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, k, num, a[N], cnt[N];
long long ans;
std::map<long long, int> map;

int main() {
    n = read(); k = read();
    for (int i = 0; i < n; i++) { a[i] = read(); cnt[a[i]]++; }
    m = *std::max_element(a, a + n);
    for (int i = 0; i < n; i++) {
        int x = a[i]; long long y = 1;
        bool flag = false;
        for (int j = 2; j * j <= m; j++) {
            if (x % j == 0) {
                int z = 0;
                while (x % j == 0) { x /= j; z++; }
                z %= k; z = (k - z) % k;
                for (int l = 0; l < z; l++) {
                    y *= j;
                    if (y > m) { flag = true; break; }
                }
                if (flag) { break; }
            }
        }
        if (!flag) {
            if (x > 1) {
                int z = (k - 1) % k;
                for (int l = 0; l < z; l++) {
                    y *= x;
                    if (y > m) { flag = true; break; }
                }
            }
            if (!flag) { ans += map[y]; }
        }
        x = a[i]; y = 1;
        for (int j = 2; j * j <= m; j++) {
            if (x % j == 0) {
                int z = 0;
                while (x % j == 0) { x /= j; z++; }
                z %= k;
                for (int l = 0; l < z; l++) { y *= j; }
            }
        }
        y *= x; map[y]++;
    }
    printf("%I64d\n", ans);
    return 0;
}