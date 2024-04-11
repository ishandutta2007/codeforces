#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, k, rt[2][N], x[N], y[N], pos[2][N];
vector <int> vec[2][N];

map <string, int> mp;
char s[15];

int find_rt(int u, int id) {
    return rt[id][u] == u ? u : rt[id][u] = find_rt(rt[id][u], id);
}

int main() {
//    freopen("1.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) rt[0][i] = rt[1][i] = i;
    for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &y[i]);
    for (int runs = 0; runs < 2; runs ++) {
        for (int i = 1; i <= k; i ++) {
            scanf("%s", s);
            int sz, id, j = i;
            if (runs == 0) mp[s] = i;
            else j = mp[s];
            scanf("%d %d", &id, &sz); pos[runs][j] = id;
            while (sz --) {
                int x;
                scanf("%d", &x);
                vec[runs][id].push_back(x);
            }
        }
        while (1) {
            bool fg = 1;
            for (int i = 1; i <= n; i ++) {
                if (find_rt(i, runs) != i) continue;
                int sz = vec[runs][i].size();
                for (int j = 0; j < sz; j ++) {
                    int id = vec[runs][i][j];
                    int u = find_rt(x[id], runs), v = find_rt(y[id], runs);
                    if (u != v && (u == i || v == i)) {
                        if (v == i) swap(u, v);
                        for (auto c : vec[runs][v]) vec[runs][u].push_back(c);
                        vec[runs][v].clear();
                        rt[runs][v] = u; fg = 0;
                    }
                }
            }
            if (fg) break;
        }
    }
    bool ans = 1;
    for (int i = 1; i <= n; i ++) {
        if (find_rt(i, 1) != i) continue;
        int j = find_rt(i, 0);
        if (find_rt(j, 1) != i) ans = 0;
        else {
            rt[1][j] = rt[1][i] = j;
            swap(vec[1][i], vec[1][j]);
        }
    }
    for (int i = 1; i <= k; i ++) if (find_rt(pos[0][i], 0) != find_rt(pos[1][i], 1)) ans = 0;
    for (int i = 1; i <= n; i ++) if (find_rt(i, 0) != find_rt(i, 1)) ans = 0;
    for (int i = 1; i <= n; i ++) {
        int sz = vec[0][i].size();
        for (int j = 0; j < 2; j ++) sort(vec[j][i].begin(), vec[j][i].end());
        if (vec[1][i].size() != sz) ans = 0;
        else {
            for (int j = 0; j < sz; j ++) if (vec[0][i][j] != vec[1][i][j]) ans = 0;
        }
    }

    puts(ans ? "YES" : "NO");
}