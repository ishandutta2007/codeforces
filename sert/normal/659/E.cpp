#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
int n, m, v1, v2, ans;
vector <int> es[N];
int c[N];

int dfs(int v, int pr) {
    if (c[v] == 1)
        return 1;
    if (c[v] == 2)
        return 0;
    c[v] = 1;
    for (int i = 0; i < es[v].size(); i++)
        if (es[v][i] != pr && dfs(es[v][i], v))
            return 1;
    c[v] = 2;
    return 0;
}

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    for (int i = 0; i < n; i++)
        if (!c[i])
            ans += !dfs(i, i);
    printf("%d", ans);
    return 0;
}