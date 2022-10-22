#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1007;
const double EPS = 1e-8;

int n, m;

int gr[MAXN][MAXN];

void bfs(int s, vector <int> &d) {
    d.resize(n, INF);
    d[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 0; u < n; u++) {
            if (!gr[v][u] || d[u] != INF) continue;
            d[u] = d[v] + 1;
            q.push(u);
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector <int> ds, dt;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v][u] = 1;
        gr[u][v] = 1;
    }
    bfs(s, ds);
    bfs(t, dt);
    int l = ds[t];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gr[i][j]) continue;
            if (ds[i] + dt[j] + 1 >= l && ds[j] + dt[i] + 1 >= l) {
                cnt++;
            }
        }
    }
    cout << cnt;
}