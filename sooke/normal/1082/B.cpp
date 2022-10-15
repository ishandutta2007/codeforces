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

int n, m, ans, cnt, a[maxN];
bool typ[maxN];
std::string s;

int main() {
    std::cin >> n >> s; s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] != s[i]) {
            typ[++m] = s[i] == 'G';
            if (s[i] == 'G') { cnt++; }
        }
        a[m]++;
    }
    for (int i = 1; i <= m; i++) {
        if (typ[i]) { ans = std::max(ans, a[i]); }
    }
    if (cnt >= 2) { ans++; }
    for (int i = 1; i <= m; i++) {
        if (typ[i] && i + 2 <= m && typ[i + 2]) {
            if (a[i + 1] == 1) {
                ans = std::max(ans, a[i] + a[i + 2]);
                if (cnt >= 3) { ans = std::max(ans, a[i] + a[i + 2] + 1); }
            }
        }
    }
    std::cout << ans;
    return 0;
} ///