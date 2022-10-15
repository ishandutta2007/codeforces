#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, ans, cnt, now, t, c;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> t >> c;
        ans = std::max(ans, cnt = std::max(0, cnt + now - t) + c), now = t;
    }
    std::cout << now + cnt << " " << ans << std::endl;
    return 0;
}