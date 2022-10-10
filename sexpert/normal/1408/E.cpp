#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = array<int, 3>;

vector<edge> edges;
const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN], rep[MAXN], m, n;

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return false;
    rep[v] = u;
    return true;
}

ll kruskal() {
    iota(rep, rep + MAXN, 0);
    ll res = 0;
    sort(edges.begin(), edges.end(), [&](edge a, edge b) { return a[2] > b[2]; });
    for(auto &[u, v, w] : edges) {
        //cout << u << " " << v << " " << w << '\n';
        if(join(u, v))
            res += w;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];

    for(int j = 1; j <= n; j++)
        cin >> b[j];

    ll tot = 0;
    for(int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        while(s--) {
            int j;
            cin >> j;
            tot += a[i] + b[j];
            edges.push_back({i, m + j, a[i] + b[j]});
        }
    }

    cout << tot - kruskal() << '\n';
}