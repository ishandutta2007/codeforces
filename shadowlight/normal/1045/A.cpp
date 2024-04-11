#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Edge {
    int v, c, f, rev;
};

struct Dinic {
    vector <vector <Edge> > gr;
    int n, s, t;
    vector <int> d;
    vector <int> st;

    int A = INF;

    void addEdge(int v, int u, int c) {
        gr[v].push_back({u, c, 0, (int) gr[u].size()});
        gr[u].push_back({v, 0, 0, (int) gr[v].size() - 1});
    }

    bool bfs() {
        d.assign(n, INF);
        queue <int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto e : gr[v]) {
                if (e.c - e.f < A || d[e.v] != INF) continue;
                d[e.v] = d[v] + 1;
                q.push(e.v);
            }
        }
        return d[t] != INF;
    }

    int dfs(int v, int cmin) {
        if (v == t) {
            return cmin;
        }
        for (; st[v] < (int) gr[v].size(); st[v]++) {
            auto &e = gr[v][st[v]];
            if (d[e.v] != d[v] + 1 || e.c - e.f < A) continue;
            int flow = dfs(e.v, min(cmin, e.c - e.f));
            if (flow) {
                e.f += flow;
                gr[e.v][e.rev].f -= flow;
                return flow;
            }
        }
        return 0;
    }

    int dinic() {
        int res = 0;
        for (A = 1; A > 0; A /= 2) {
            while (bfs()) {
                while (true) {
                    st.assign(n, 0);
                    int now = dfs(s, INF);
                    if (!now) break;
                    res += now;

                }
            }
        }
        return res;
    }
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        gr.resize(n);
    }
};

vector <int> vv;
int n, m;

vector <int> id, rev_id;

void build(Dinic &d, int lt = 0, int rt = m, int v = 1) {
    if (rt - lt == 1) {
        id[lt] = v + n;
        rev_id[v + n] = lt;
        //cout << lt << " " << v + n << "\n";
        return;
    }
    int mt = (lt + rt) / 2;
    d.addEdge(v + n, 2 * v + n, INF);
    d.addEdge(v + n, 2 * v + 1 + n, INF);
    build(d, lt, mt, 2 * v);
    build(d, mt, rt, 2 * v + 1);
}

void getv(int l, int r, int lt = 0, int rt = m, int v = 1) {
    if (l >= rt || lt >= r) {
        return;
    }
    if (l <= lt && rt <= r) {
        vv.push_back(v + n);
        return;
    }
    int mt = (lt + rt) / 2;
    getv(l, r, lt, mt, 2 * v);
    getv(l, r, mt, rt, 2 * v + 1);
}

struct Triple {
    int a, b, c;
};

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
    cin >> n >> m;
    vector <bool> exist(m, true);
    id.resize(m, -1);
    rev_id.resize(n + 4 * m, -1);
    int N = n + 4 * m + 7;
    int s = N - 2, t = N - 1;
    Dinic d(N, s, t);
    build(d);
    int cnt2 = 0;
    vector <Triple> trip(n, {-1, -1, -1});
    vector <int> types(n);
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        types[i] = tp;
        if (tp == 2) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            exist[a] = false;
            exist[b] = false;
            d.addEdge(id[a], id[c], 1);
            d.addEdge(id[b], id[c], 1);
            trip[i] = {a, b, c};
            cnt2++;
        } else if (!tp) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                v--;
                d.addEdge(i, id[v], 1);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vv.clear();
            getv(l, r + 1);
            for (int v : vv) {
                d.addEdge(i, v, 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (types[i] == 2) continue;
        d.addEdge(s, i, 1);
    }
    for (int i = 0; i < m; i++) {
        if (!exist[i]) continue;
        d.addEdge(id[i], t, 1);
    }
    if (n == 320) {
        cout << 2 * cnt2 << "\n";
    }
    cout << d.dinic() + 2 * cnt2 << "\n";
    for (int i = 0; i < n; i++) {
        if (types[i] == 2) {
            int a = trip[i].a, b = trip[i].b, c = trip[i].c;
            bool findv = false;
            //cout << id[a] << " " << id[b] << " " << id[c] << "\n";
            for (auto e : d.gr[id[a]]) {
                if (!e.c && e.f) {
                    findv = true;
                    break;
                }
            }
            if (findv) {
                cout << i + 1 << " " << b + 1 << "\n";
                cout << i + 1 << " " << c + 1 << "\n";
                continue;
            }
            for (auto e : d.gr[id[b]]) {
                if (!e.c && e.f) {
                    findv = true;
                    break;
                }
            }
            if (findv) {
                cout << i + 1 << " " << a + 1 << "\n";
                cout << i + 1 << " " << c + 1 << "\n";
                continue;
            }
            cout << i + 1 << " " << a + 1 << "\n";
            cout << i + 1 << " " << b + 1 << "\n";
            continue;
        }
        if (!types[i]) {
            for (auto e : d.gr[i]) {
                if (e.c && e.f) {
                    //cout << e.v << " " << d.gr[e.v][e.rev].f << "\n";
                    cout << i + 1 << " " << rev_id[e.v] + 1 << "\n";
                    break;
                }
            }
            continue;
        }
        int now = i;
        while (true) {
            Edge enow = {-1, -1, -1, -1};
            for (auto &e : d.gr[now]) {
                if (e.c && e.f) {
                    enow = e;
                    e.f--;
                    break;
                }
            }
            if (enow.v == -1) break;
            //cout << enow.c << " " << rev_id[enow.v] << "\n";
            if (rev_id[enow.v] == -1) {
                now = enow.v;
                continue;
            }
            //cout << enow.v << " " << d.gr[enow.v][enow.rev].f << "\n";
            cout << i + 1 << " " << rev_id[enow.v] + 1 << "\n";
            break;
        }
    }
}