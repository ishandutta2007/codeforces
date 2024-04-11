#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;
const vector<int> BIG = {-1, -1, -1, -1, -1, -1, -1, -1};

struct Graph {
    int n;
    vector<vector<int>> es;

    Graph(int nn) {
        n = nn;
        es.resize(n);
        for (int i = 0; i < n; i++) es[i].clear();
    }

    void addE(int v1, int v2) {
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    vector<int> bfs(int st, int fn, int bad = -1) {
        vector<int> dist(n, -1), pr(n, -1);
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w: es[v]) {
                if (dist[w] == -1 && w != bad) {
                    dist[w] = dist[v] + 1;
                    pr[w] = v;
                    q.push(w);
                }
            }
        }

        if (dist[fn] == -1) return BIG;
        vector<int> path;
        int v = fn;
        while (v != -1) {
            path.push_back(v);
            v = pr[v];
        }
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> path4() {
        vector<bool> u(n, false);
        u[0] = true;
        for (int c: es[0]) u[c] = true;
        for (int c: es[0]) {
            for (int w: es[c]) {
                if (!u[w]) {
                    return {0, c, w, 0, n - 1};
                }
            }
        }
        return BIG;
    }

    void dfs_cmp(int v, vector<bool> &u, vector<bool> &isc, vector<int> &cmp, int cmp_num, vector<int> &vert, ll &V, ll &E) {
        if (u[v] || !isc[v]) return;
        u[v] = true;
        V++;
        vert.push_back(v);
        cmp[v] = cmp_num;
        for (int w: es[v]) {
            if (isc[w]) {
                E++;
                dfs_cmp(w, u, isc, cmp, cmp_num, vert, V, E);
            }
        }
    }

    vector<int> go5(int a, int b) {
        vector<int> path = bfs(a, b, 0);
        vector<int> ps(n, N);
        for (int i = 0; i < (int)path.size(); i++) ps[path[i]] = i;
        int min_pos = N;
        for (int w: es[b]) {
            min_pos = min(min_pos, ps[w]);
        }
        return {0, b, path[min_pos], path[min_pos - 1], b, n - 1};
    }

    vector<int> go(vector<int> &vert, vector<bool> &isc) {
        vector<bool> her(n, false);
        for (int v: vert) her[v] = true;
        int V = vert.size();

        vector<int> lst(n, -1);
        for (int v: vert) {
            int cnt = 0;
            for (int w: es[v]) {
                if (isc[w]) cnt++;
                lst[w] = v;
            }

            if (cnt != V - 1) {
                for (int w: vert) {
                    if (w != v && lst[w] != v) {
                        return go5(v, w);
                    }
                }
            }
        }
        exit(12);
    }

    vector<int> path5() {
        vector<bool> u(n, false);
        vector<bool> isc(n, false);
        vector<int> cmp(n, -1);
        for (int w: es[0]) isc[w] = true;

        int cmp_num = 0;
        for (int w: es[0]) {
            if (!u[w]) {
                vector<int> vert;
                ll V = 0, E = 0;
                dfs_cmp(w, u, isc, cmp, cmp_num, vert, V, E);
                cmp_num++;
                //cerr << V << " " << E << "\n";
                if (E < V * V - V) {
                    return go(vert, isc);
                }
            }
        }
        return BIG;
    }
};

void solve() {
    int n, m, v1, v2;
    scanf("%d%d", &n, &m);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        g.addE(v1 - 1, v2 - 1);
    }

    vector<int> pathB = g.bfs(0, n - 1);
    vector<int> pathC = g.path4();
    if ((int)pathC.size() == (int)BIG.size()) pathC = g.path5();

    vector<int> ans = pathC;
    if ((int)pathB.size() < (int)ans.size()) ans = pathB;

    if ((int)ans.size() == BIG.size()) {
        printf("-1\n");
    } else {
        printf("%d\n", (int)ans.size() - 1);
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%d ", ans[i] + 1);
        }
        printf("\n");
    }
}

int main() {
    init();
	solve();
	//solve();
	//solve();
	//solve();
    return 0;
}