#include <bits/stdc++.h>

using namespace std;



#define N 200005



int n, m, tot;

int s[N], dep[N], ans[N], fa[N];

int uu[N], vv[N];

vector<int> v[N];

bool vis[N];



void dfs(int x, int par = 0) {

    vis[x] = 1;

    fa[x] = par;

    dep[x] = dep[par] + 1;

    ans[x] = s[x];

    for (int i = 0; i < v[x].size(); i ++) {

        int y = v[x][i];

        if (vis[y]) continue;

        dfs(y, x);

        ans[x] += ans[y];

    }

}



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {

        scanf("%d", &s[i]);

        tot += s[i];

    }

    if (tot) return puts("Impossible"), 0;

    puts("Possible");

    scanf("%d", &m);

    for (int i = 0; i < m; i ++) {

        int x, y;

        scanf("%d %d", &x, &y);

        v[x].push_back(y), v[y].push_back(x);

        uu[i] = x, vv[i] = y;

    }

    dfs(1);

    for (int i = 0; i < m; i ++) {

        int x = uu[i], y = vv[i];

        if (dep[x] > dep[y]) printf("%d\n", fa[x] == y ? -ans[x] : 0);

        else printf("%d\n", fa[y] == x ? ans[y] : 0);

    }

    return 0;

}