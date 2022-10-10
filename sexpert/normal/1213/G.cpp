#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
ll ans = 0, res[MAXN];
int rep[MAXN], sz[MAXN];

int find(int u) {
    return rep[u] == 0 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    if(sz[v] > sz[u])
        swap(u, v);
    ans += (ll)sz[u]*sz[v];
    rep[v] = u;
    sz[u] += sz[v];
}

vector<array<int, 4>> events;

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        sz[i] = 1;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        events.push_back({w, 0, u, v});
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        events.push_back({x, 1, i, -1});
    }
    sort(events.begin(), events.end());
    for(auto e : events) {
        if(e[1] == 0)
            join(e[2], e[3]);
        else
            res[e[2]] = ans;
    }
    for(int i = 0; i < q; i++)
        cout << res[i] << " ";
    cout << '\n';
}