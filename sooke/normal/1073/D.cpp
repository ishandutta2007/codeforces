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

typedef long long lol;

const int maxN = 200005;

int n, a[maxN];
lol k, ans, cnt, sum;

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    while (true) {
        sum = cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (k >= a[i]) { k -= a[i]; sum += a[i]; ans++; cnt++; }
            if (!k) { break; }
        }
        if (!k || !sum) { break; }
        ans += k / sum * cnt; k %= sum;
    }
    std::cout << ans << std::endl;
    return 0;
} ///