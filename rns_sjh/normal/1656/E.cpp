#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100500;

int vis[N], dep[N], sub[N], a[N];

vector<int> vec[N], con[N], vc[N];

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < con[u].size(); i++) {
        int v = con[u][i];
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        vec[u].push_back(v);
        dfs(v);
    }
}

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            con[i].clear(), vc[i].clear(), vec[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            con[u].push_back(v);
            con[v].push_back(u);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) {
            vc[dep[i]].push_back(i);
        }
        for (int i = n; i >= 1; i--) {
            if (vc[i].size() == 0) continue;
            for (int j = 0; j < vc[i].size(); j++) {
                int v = vc[i][j];
                if (i % 2) sub[v] = 1;
                else sub[v] = -1;
            }
        }
        for (int i = 2; i <= n; i++) {
            a[i] = sub[i];
            for (int j = 0; j < vec[i].size(); j++) {
                int v = vec[i][j];
                a[i] -= sub[v];
            }
        }
        a[1] = con[1].size();
        a[1] = -a[1];
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}