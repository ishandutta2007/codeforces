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

const int maxN = 500005;

int n, m, a[maxN], b[maxN];
std::string s, t;
long long l, r, ans;
bool flag;

int main() {
    std::cin >> n >> m >> s >> t; s = " " + s; t = " " + t;
    for (int i = 1; i <= n; i++) { a[i] = s[i] == 'b'; b[i] = t[i] == 'b'; }
    for (int i = 1; i <= n; i++) {
        if (!flag) { l = l << 1 | a[i]; r = r << 1 | b[i]; }
        if (r - l + 1 >= m) { flag = true; }
        if (flag) { ans += m; } else { ans += r - l + 1; }
    }
    std::cout << ans << std::endl;
    return 0;
} //