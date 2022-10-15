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

const int maxN = 200005;

int n, x, y, tx, ty, px, py, ans = -1, len, cnt[5][maxN];
std::string s;
bool flag;

int main() {
    std::cin >> n >> s >> y >> x; s = " " + s;
    for (int i = 1; i <= n; i++) {
        cnt[0][i] = cnt[0][i - 1] + (s[i] == 'U');
        cnt[1][i] = cnt[1][i - 1] + (s[i] == 'D');
        cnt[2][i] = cnt[2][i - 1] + (s[i] == 'R');
        cnt[3][i] = cnt[3][i - 1] + (s[i] == 'L');
    }
    tx = cnt[0][n] - cnt[1][n]; ty = cnt[2][n] - cnt[3][n];
    for (int l = 0, r = n / 2, mid; l <= r; ) {
        mid = l + r >> 1; len = mid << 1; flag = false;
        for (int i = len; i <= n; i++) {
            px = x - (tx - (cnt[0][i] - cnt[0][i - len]) + (cnt[1][i] - cnt[1][i - len]));
            py = y - (ty - (cnt[2][i] - cnt[2][i - len]) + (cnt[3][i] - cnt[3][i - len]));
            if (std::abs(px) + std::abs(py) <= len) {
                if ((len - std::abs(px) - std::abs(py)) % 2 == 0) { flag = true; }
            }
        }
        if (flag) { r = mid - 1; ans = len; } else { l = mid + 1; }
    }
    for (int l = 0, r = n / 2, mid; l <= r; ) {
        mid = l + r >> 1; len = mid << 1 | 1; flag = false;
        for (int i = len; i <= n; i++) {
            px = x - (tx - (cnt[0][i] - cnt[0][i - len]) + (cnt[1][i] - cnt[1][i - len]));
            py = y - (ty - (cnt[2][i] - cnt[2][i - len]) + (cnt[3][i] - cnt[3][i - len]));
            if (std::abs(px) + std::abs(py) <= len) {
                if ((len - std::abs(px) - std::abs(py)) % 2 == 0) { flag = true; }
            }
        }
        if (flag) { r = mid - 1; ans = ans == -1 ? len : std::min(ans, len); } else { l = mid + 1; }
    }
    std::cout << ans << std::endl;
    return 0;
} //