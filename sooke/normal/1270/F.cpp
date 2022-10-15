#include <bits/stdc++.h>

const int N = 1e6 + 5, S = 100;

int n, m, rmax, x[N], y[N], l[N], r[N];
long long ans, a[N];
std::string str;

int main() {
    std::cin >> str; n = str.size(); str = " " + str;
    for (int i = 0; i <= n + 1; i++) {
        l[i] = 1e9; r[i] = -1e9;
    }
    for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1]; y[i] = y[i - 1];
        if (str[i] == '1') {
            x[i]++;
        } else {
            y[i]++;
        }
        l[x[i]] = std::min(l[x[i]], y[i]);
        r[x[i]] = std::max(r[x[i]], y[i]);
        rmax = std::max(rmax, y[i]);
    }
    for (int i = 0; i <= S; i++) {
        m = 0;
        for (int j = 0; j <= n; j++) {
            a[m++] = y[j] - 1ll * x[j] * i;
        }
        std::sort(a, a + m); a[m] = 1e18;
        long long lst = 1e17;
        for (int j = 0, c = 0; j <= m; j++) {
            if (lst != a[j]) {
                ans += 1ll * c * (c - 1) / 2;
                c = 0;
            }
            lst = a[j]; c++;
        }
    }
    for (int i = 0; i <= n; i++) {
        int now = y[i] + S + 1;
        for (int j = x[i] + 1, k = 1, x, _l, _r; now <= rmax; j++, k++) {
            x = (k - now % k) % k;
            _l = std::max(((l[j] + x - 1) / k + 1) * k, now + x);
            _r = (r[j] + x) / k * k; 
            ans += std::max(0ll, (0ll + _r - _l + k) / k);
            now += S + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}