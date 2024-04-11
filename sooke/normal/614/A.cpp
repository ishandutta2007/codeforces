#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

lol l, r, x, now = 1, pre;
bool flag = true;

int main() {
    std::cin >> l >> r >> x;
    while (true) {
        if (l <= now && now <= r) { std::cout << now << " "; flag = false; } pre = now;
        if (now > r / x) { break; } else { now *= x; }
        if (now == pre) { break; }
    }
    if (flag) { std::cout << -1 << std::endl; }
    return 0;
}