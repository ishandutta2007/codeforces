#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 17;

int n, cnt, p[maxN], x[maxN];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> p[i]; }
    for (int i = 1; i <= n; i++) { std::cin >> x[i]; }
    for (int i = 0; i < 720720; i++) {
        bool flag = false;
        for (int j = 1; j <= n; j++) { flag |= i % p[j] == x[j]; }
        if (flag) { cnt++; }
    }
    printf("%.5lf\n", cnt / 720720.0);
    return 0;
}