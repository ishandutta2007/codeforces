#include <bits/stdc++.h>

int n, l, r;

long long solve1() {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (i < l) {
            res += 1 << i;
        } else {
            res += 1;
        }
    }
    return res;
}
long long solve2() {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (i < r) {
            res += 1 << i;
        } else {
            res += 1 << (r - 1);
        }
    }
    return res;
}

int main() {
    std::cin >> n >> l >> r;
    std::cout << solve1() << " " << solve2() << std::endl;
    return 0;
}