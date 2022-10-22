#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <int> p, r;
int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
}

bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
    if (r[v] == r[u]) r[u]++;
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
    return true;
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
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > edges(m);
    vector <pair <int, int> > res;
    vector <vector <int> > gr(n);
    vector <int> st(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        st[v]++, st[u]++;
        edges[i] = {v, u};
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    int mst = 0, v = -1;
    for (int i = 0; i < n; i++) {
        if (st[i] > mst) {
            mst = st[i];
            v = i;
        }
    }
    p.resize(n, 0);
    r.resize(n, 0);
    iota(p.begin(), p.end(), 0);
    for (int u : gr[v]) {
        res.push_back({v, u});
        uni(v, u);
    }
    for (int i = 0; i < m; i++) {
        int v = edges[i].first, u = edges[i].second;
        if (uni(v, u)) {
            res.push_back({v, u});
        }
    }
    for (auto t : res) {
        cout << t.first + 1 << " " << t.second + 1 << "\n";
    }
}