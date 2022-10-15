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

const int maxN = 100005;

int n, a[maxN], pre[6][maxN];
bool f[6][maxN];

void dfs(int dep, int u) {
    if (dep > 1) { dfs(dep - 1, pre[u][dep]); }
    printf("%d ", u);
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    f[1][1] = f[2][1] = f[3][1] = f[4][1] = f[5][1] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            if (f[j][i - 1]) {
                for (int k = 1; k <= 5; k++) {
                    if (a[i - 1] == a[i] && j != k) { f[k][i] = true; pre[k][i] = j; }
                    if (a[i - 1] < a[i] && j < k) { f[k][i] = true; pre[k][i] = j; }
                    if (a[i - 1] > a[i] && j > k) { f[k][i] = true; pre[k][i] = j; }
                }
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        if (f[i][n]) { dfs(n, i); return 0; }
    }
    printf("-1\n");
    return 0;
} //