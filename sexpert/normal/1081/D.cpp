#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int numSpecial[MAXN], parent[MAXN], rnk[MAXN], n, m, k;

int find(int u) {
    return (parent[u] == 0 ? u : parent[u] = find(parent[u]));
}

void join(int u, int v) {
    int a = find(u), b = find(v);
    if(a != b) {
        if(rnk[a] < rnk[b])
            swap(a, b);
        if(rnk[a] == rnk[b])
            rnk[a]++;
        parent[b] = a;
        numSpecial[a] += numSpecial[b];
    }
}

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w){}

    bool operator<(edge o) {
        return w < o.w;
    }
};

vector<edge> edges;

int kruskal() {
    sort(edges.begin(), edges.end());
    for(auto e : edges) {
        join(e.u, e.v);
        if(numSpecial[find(e.u)] == k)
            return e.w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        numSpecial[x] = 1;
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        //cout << u << " " << v << " " << w << endl;
        edges.push_back(edge(u, v, w));
    }
    int ans = kruskal();
    for(int i = 0; i < k; i++)
        cout << ans << " ";
}