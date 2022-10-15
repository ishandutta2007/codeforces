#include <bits/stdc++.h>

long long a, b, n, ans;

int main() {
    std::cin >> a >> b >> n;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i + j == n) { ans++; }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}