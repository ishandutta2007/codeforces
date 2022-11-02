#include <bits/stdc++.h>
using namespace std;

#define N 505

int n, m;
vector <int> adj[N];
const int inf = 1e9;

struct state{
    int u, v, s, val;
    state *pa;
    state(int u = 0, int v = 0, int s = 0, int val = inf, state *pa = NULL) : u(u), v(v), s(s), val(val), pa(pa) {}
} dp[N][N][2];

int main() {
    scanf("%d %d", &n, &m);
    while (m --) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp[n][1][0] = state(n, 1, 0, 0);
    queue <state*> Q;
    Q.push(&dp[n][1][0]);
    while (!Q.empty()) {
        state *s = Q.front(); Q.pop();
        int u = s -> u, v = s -> v;
        if (s -> s) {
            for (auto w : adj[v]) {
                if (w != u && dp[u][w][0].val == inf) {
                    dp[u][w][0] = state(u, w, 0, s -> val + 1, s);
                    Q.push(&dp[u][w][0]);
                }
            }
        }
        else {
            for (auto w : adj[u]) {
                if (dp[w][v][1].val == inf) {
                    dp[w][v][1] = state(w, v, 1, s -> val + 1, s);
                    Q.push(&dp[w][v][1]);
                }
            }
        }
    }
    if (dp[1][n][0].val == inf) puts("-1");
    else {
        vector <int> vec;
        int u = 1, v = n, s = 0;
        vec.push_back(v), vec.push_back(u);
        while (1) {
            state *st = dp[u][v][s].pa;
            if (st == NULL) break;
            if (s) {
                u = st -> u;
                vec.push_back(u);
            }
            else {
                v = st -> v;
                vec.push_back(v);
            }
            s ^= 1;
        }
        int sz = vec.size();
        printf("%d\n", sz / 2 - 1);
        for (int i = 1; i < sz; i += 2) printf("%d ", vec[i]); puts("");
        for (int i = 0; i < sz; i += 2) printf("%d ", vec[i]); puts("");
    }

}