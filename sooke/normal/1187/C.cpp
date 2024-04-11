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

int n, m;
std::vector<int> l[2], r[2];
bool f[1005];

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int opt, _l, _r; std::cin >> opt;
        std::cin >> _l >> _r; l[opt].push_back(_l); r[opt].push_back(_r);
        if (opt == 1) {
            for (int j = _l + 1; j <= _r; j++) { f[j] = true; }
        }
    }
    for (int i = 0; i < (int) l[0].size(); i++) {
        bool flag = true;
        for (int j = l[0][i] + 1; j <= r[0][i]; j++) { flag &= f[j]; }
        if (flag) { printf("NO\n"); exit(0); }
    }
    printf("YES\n10000000 ");
    for (int i = 2, j = 10000000; i <= n; i++) {
        printf("%d ", f[i] ? j : --j);
    }
    return 0;
}