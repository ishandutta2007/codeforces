#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, x[N], y[N], val[N];
bool dp[N][N];

bool cmp(int s, int t, int k) {
    while (k >= 0) {
        if (dp[s][k] != dp[t][k]) return dp[s][k] < dp[t][k];
        k --;
    }
    return 0;
}

vector <int> adj[N];

void dfs(int u, int pa = 0) {
    vector <int> vec;
    for (auto e : adj[u]) {
        int v = x[e] ^ y[e] ^ u;
        if (v == pa) continue;
        dfs(v, u);
        vec.push_back(e);
    }
    stack <int> st;
    for (int i = N - 1; i >= 0; i --) {
        int cnt = 0;
        for (auto e : vec) {
            int v = x[e] ^ y[e] ^ u;
            if (dp[v][i]) cnt ++;
        }
        assert(cnt <= 1);
        if (cnt == 1) dp[u][i] = 1;
        else {

            bool chk = true;
            vector <int> alive = vec;
            for (int j = i - 1; j >= 0; j --) {
                int cnt = 0, mx = -1, mxe;
                for (auto e : alive) {
                    int v = x[e] ^ y[e] ^ u;
                    if (dp[v][j]) {
                        cnt ++;
                    }
                    else if (mx < 0 || cmp(mx, v, j)) mx = v, mxe = e;
                }
                if (cnt >= 2) {
                    chk = false; break;
                }
                if (cnt == 0) {
                    for (auto &e : alive) if (e == mxe) {
                        swap(e, alive.back());
                        alive.pop_back(); break;
                    }
                }
            }
            if (!alive.empty()) chk = false;
            if (chk) continue;

            dp[u][i] = 1;
            int mx = -1, mxe;
            for (auto e : vec) {
                int v = x[e] ^ y[e] ^ u;
                if (mx < 0 || cmp(mx, v, i)) mx = v, mxe = e;
            }
            val[mxe] = i;
            for (auto &e : vec) if (e == mxe) {
                swap(e, vec.back());
                vec.pop_back(); break;
            }

        }
    }

}

int query(int e) {
    printf("? %d %d\n", x[e], y[e]);
    fflush(stdout);
    int u;
    scanf("%d", &u);
    return u;
}

bool vis[N];

vector <int> edge;

void dfs_edge(int u, int pa = 0) {
    for (auto e : adj[u]) {
        if (vis[e]) continue;
        int v = x[e] ^ y[e] ^ u;
        if (v != pa) edge.push_back(e), dfs_edge(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(i);
        adj[v].push_back(i);
        x[i] = u, y[i] = v;
    }
    dfs(1);

    int u = 1;
    while (1) {
        edge.clear(); dfs_edge(u);
        if (edge.empty()) break;
        int e = *max_element(edge.begin(), edge.end(), [&](int a, int b) {return val[a] < val[b];});
        u = query(e), vis[e] = 1;
    }
    printf("! %d\n", u);
    fflush(stdout);

    return 0;
}