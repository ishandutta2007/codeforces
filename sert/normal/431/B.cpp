#include <cstdio>
#include <algorithm>
int g[6][6], p[6], ans, t;
int main() {
    //freopen("a.in", "r", stdin);
    for (int i = 0; i < 5; p[i] = i++) for (int j = 0; j < 5; j++) scanf("%d", &g[i][j]);
    while (true) {
        t = g[p[0]][p[1]] + g[p[1]][p[0]] + g[p[2]][p[1]] + g[p[1]][p[2]] + 2 * (g[p[2]][p[3]] + g[p[3]][p[2]] + g[p[3]][p[4]] + g[p[4]][p[3]]);
        if (ans < t) ans = t;
        if (!std::next_permutation(p, p + 5)) break;
    }
    printf("%d", ans);
}