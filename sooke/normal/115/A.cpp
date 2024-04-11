#include <cstdio>
#include <vector>
#include <algorithm>

const int maxN = 2005;

int n, ans;
std::vector<int> e[maxN];

void dfs(int u, int dep) {
    ans = std::max(ans, dep);
    for (int i = 0; i < (int) e[u].size(); i++) { dfs(e[u][i], dep + 1); }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u; scanf("%d", &u);
        e[std::max(u, 0)].push_back(i);
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}