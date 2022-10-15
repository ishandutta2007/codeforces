#include <bits/stdc++.h>

long long n, ans;

int main() {
    std::cin >> n;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != 1) { ans = std::__gcd(ans, i); }
            ans = std::__gcd(ans, n / i);
        }
    }
    std::cout << ans;
    return 0;
}