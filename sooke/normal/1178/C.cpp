#include <bits/stdc++.h>

const int mod = 998244353;

int n, m, ans = 1;

int main() {
    std::cin >> n >> m;
    for (; n; n--) { ans = (ans + ans) % mod; }
    for (; m; m--) { ans = (ans + ans) % mod; }
    std::cout << ans << std::endl;
    return 0;
}