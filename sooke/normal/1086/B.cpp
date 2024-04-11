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

const int maxN = 200005;

long long n, m, cnt, deg[maxN];

int main() {
    std::cin >> n >> m;
    for (int i = 2; i <= n; i++) { int u, v; std::cin >> u >> v; deg[u]++; deg[v]++; }
    for (int i = 1; i <= n; i++) { cnt += deg[i] == 1; }
    printf("%.7lf\n", (double) m / ((double) cnt / 2.0));
    return 0;
}