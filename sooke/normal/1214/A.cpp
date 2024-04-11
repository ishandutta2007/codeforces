#include <bits/stdc++.h>

long long n, a, b, ans = 1e18;

int main() {
    std::cin >> n >> a >> b; b *= 5;
    for (int i = 0; i <= n; i++) {
        if (n - i * a < 0) { break; }
        ans = std::min(ans, (n - i * a) % b);
    }
    std::cout << ans << std::endl;
    return 0;
}