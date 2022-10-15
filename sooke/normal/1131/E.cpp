#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

const int maxN = 100005;
const long long lim = 1e9 + 5;

int n, m;
long long ans, f[26];
std::string str;
bool o[maxN];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, l, r, x; i <= n; i++) {
        std::cin >> str; m = (int) str.size(); str = " " + str;
        l = r = 0;
        for (int j = 1; j <= m; j++) {
            if (str[1] == str[j]) { l++; } else { break; }
        }
        for (int j = m; j >= 1; j--) {
            if (str[m] == str[j]) { r++; } else { break; }
        }
        for (int k = 0; k < 26; k++) {
            x = 0;
            for (int j = 1, lst = 0; j <= m; j++) {
                if (str[j] - 'a' == k) { x = std::max(x, j - lst); } else { lst = j; }
            }
            if (l == m && str[1] - 'a' == k) { f[k] = f[k] + (f[k] + 1) * m; } else {
                if (o[k]) { f[k] = (str[1] - 'a' == k ? l : 0) + (str[m] - 'a' == k ? r : 0) + o[k]; } else { f[k] = o[k]; }
            }
            f[k] = std::min(std::max(f[k], (long long) x), lim);
            for (int j = 1; j <= m; j++) {
                if (str[j] - 'a' == k) { o[k] = true; }
            }
        }
    }
    for (int i = 0; i < 26; i++) { ans = std::max(ans, f[i]); }
    std::cout << ans;
    return 0;
}