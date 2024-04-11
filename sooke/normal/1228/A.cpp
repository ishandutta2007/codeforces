#include <bits/stdc++.h>

int l, r;

bool check(int x) {
    bool used[10];
    for (int i = 0; i < 10; i++) { used[i] = false; }
    while (x != 0) {
        if (used[x % 10]) { return false; }
        used[x % 10] = true;
        x /= 10;
    } return true;
}

int main() {
    std::cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            std::cout << i << std::endl; return 0;
        }
    } std::cout << -1 << std::endl;
    return 0;
}