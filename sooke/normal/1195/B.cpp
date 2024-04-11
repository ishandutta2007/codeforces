#include <bits/stdc++.h>

long long n, k;

int main() {
    std::cin >> n >> k;
    for (int i = 0; i <= 1000000; i++) {
        if (1ll * i * (i + 1) / 2 + i == n + k) {
            printf("%d\n", n - i); break;
        }
    }
    return 0;
}