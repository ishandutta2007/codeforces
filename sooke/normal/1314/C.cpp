#include <bits/stdc++.h>

const int N = 1e3 + 5;
const long long W = 1e18 + 5;

int n, m, ans, anss, g[N];
long long k, f[N][N];
std::string str, s[N];

long long solve(std::string t) {
    for (int i = 1; i <= n; i++) {
        g[i] = i - 1;
        for (int j = i, jj = 0; j <= n; j++, jj++) {
            if (jj >= t.size()) {
                g[i] = j; break;
            } else if (t[jj] > str[j]) {
                break;
            } else if (t[jj] < str[j]) {
                g[i] = j; break;
            }
        }
    }
    f[0][0] = 1;
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i <= n; i++) { f[j][i] = 0; }
        for (int i = 0; i < n; i++) {
            if (g[i + 1] >= i + 1) {
                f[j][g[i + 1]] += f[j - 1][i];
                f[j][g[i + 1]] = std::min(f[j][g[i + 1]], W);
            }
        }
        for (int i = 1; i <= n; i++) {
            f[j][i] += f[j][i - 1];
            f[j][i] = std::min(f[j][i], W);
        }
    }
    return f[m][n];
}

int main() {
    std::cin >> n >> m >> k >> str; str = " " + str;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) { s[i] += str[j]; }
    }
    std::sort(s + 1, s + n + 1);
    ans = 1;
    for (int l = 1, r = n, mid; l <= r; ) {
        mid = l + r >> 1;
        if (solve(s[mid]) >= k) {
            l = mid + 1; ans = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    anss = 1;
    for (int l = 1, r = s[ans].size(), mid; l <= r; ) {
        mid = l + r >> 1;
        std::string t;
        for (int i = 0; i < mid; i++) { t += s[ans][i]; }
        if (solve(t) >= k) {
            l = mid + 1; anss = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::string t;
    for (int i = 0; i < anss; i++) { t += s[ans][i]; }
    std::cout << t << std::endl;
    return 0;
}