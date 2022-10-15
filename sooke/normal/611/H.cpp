#include <bits/stdc++.h>

const int inf = 1e9;
const int N = 2e5 + 5, V = 25, E = 200;

int n, m, len[N], num[8], anc[8], a[8][8], b[8][8], id[8][8];
int s, t, dis[V], cur[V];
bool flag, used[8][8], vis[V];
std::vector<std::pair<int, int>> ans;
std::vector<int> vec[8];

struct List {
    int tot, fst[V], nxt[E], to[E], val[E], flw[E];

    void reset() { memset(fst, -1, sizeof(fst)); tot = 0; }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; flw[tot] = 0; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, 0);
    }
} e;

bool bfs() {
    std::queue<int> que;
    memset(dis, 60, sizeof(dis));
    memcpy(cur, e.fst, sizeof(cur));
    dis[s] = 0;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i];
            if (w > f && dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                if (v == t) { return true; }
                que.push(v);
            }
        }
    }
    return false;
}
int dinic(int u, int nowf) {
    if (u == t) { return nowf; }
    vis[u] = true;
    int lef = nowf;
    for (int &i = cur[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i], f = e.flw[i];
        if (w > f && dis[v] == dis[u] + 1 && !vis[v]) {
            int def = dinic(v, std::min(lef, w - f));
            if (def == 0) { dis[v] = -1; continue; }
            lef -= def; e.flw[i] += def; e.flw[i ^ 1] -= def;
            if (lef == 0) { break; }
        }
    }
    vis[u] = false;
    return nowf - lef;
}

int find(int i) {
    return anc[i] == i ? i : anc[i] = find(anc[i]);
}
bool check() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) { anc[i] = i; }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (used[i][j]) {
                if (a[i][j] == 0) { return false; }
                if (find(i) == find(j)) { return false; }
                anc[find(i)] = find(j); cnt++;
            }
        }
    }
    return cnt == m - 1;
}

void dfs(int i, int j) {
    if (flag) { return; }
    if (j > m) { i++; j = i + 1; }
    if (i > m) {
        if (!check()) { return; }
        int res = 0;
        e.reset();
        s = 0; t = m + 1;
        for (int i = 1; i <= m; i++) {
            e.link(s, i, num[i] - 1);
            res += num[i] - 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                id[i][j] = t++;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                e.link(id[i][j], t, a[i][j] - used[i][j]);
                e.link(i, id[i][j], inf); e.link(j, id[i][j], inf);
            }
        }
        while (bfs()) { res -= dinic(s, inf); }
        if (res > 0) { return; }
        flag = true;
        for (int i = 1; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                if (used[i][j]) {
                    ans.push_back({vec[i][0], vec[j][0]});
                }
                int u = id[i][j];
                for (int k = e.fst[u]; ~k; k = e.nxt[k]) {
                    int v = e.to[k], f = -e.flw[k];
                    if (v <= m) {
                        for (; f; f--) {
                            if (v == i) {
                                ans.push_back({vec[i][--num[i]], vec[j][0]});
                            } else {
                                ans.push_back({vec[j][--num[j]], vec[i][0]});
                            }
                        }
                    }
                }
            }
        }
        return;
    }
    used[i][j] = false;
    dfs(i, j + 1);
    used[i][j] = true;
    dfs(i, j + 1);
}

int main() {
    scanf("%d", &n);
    for (int u = 1; u <= n; u++) {
        int x = u;
        for (; x; x /= 10) { len[u]++; }
        num[len[u]]++;
        vec[len[u]].push_back(u);
    }
    m = len[n];
    for (int i = 1; i < n; i++) {
        char u[8], v[8];
        scanf("%s%s", u, v);
        int x = strlen(u), y = strlen(v);
        b[x][y]++;
        if (x > y) { std::swap(x, y); }
        a[x][y]++;
    }
    for (int i = 1; i <= m; i++) {
        num[i] -= a[i][i];
        if (num[i] <= 0) { printf("-1\n"); return 0; }
        for (int j = num[i]; j < vec[i].size(); j++) {
            ans.push_back({vec[i][j - 1], vec[i][j]});
        }
    }
    dfs(1, 2);
    if (!flag) { printf("-1\n"); return 0; }
    for (auto i : ans) {
        int u = i.first, v = i.second;
        if (b[len[u]][len[v]] > 0) {
            b[len[u]][len[v]]--;
            printf("%d %d\n", u, v);
        } else {
            b[len[v]][len[u]]--;
            printf("%d %d\n", v, u);
        }
    }
    return 0;
}