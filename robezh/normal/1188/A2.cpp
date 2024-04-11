#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1005;

struct P {
    int x, y;
};

struct edge {int u, v, cost;};

int n;
vector<int> G[N];
vector<edge> E, res;

P get_leaf(int v, int p) {
    P res = {-1, -1};
    for(int to : G[v]) {
        if(to == p) continue;
        P nxt = get_leaf(to, v);
        if(res.x == -1) {
            res.x = nxt.x;
        }
        res.y = nxt.y;
    }
    if(res.x == -1) {
        res.x = res.y = v;
    }
    return res;
}

void diff(int u, int v, int mid, int cost) {
    res.push_back({u, mid, cost / 2});
    res.push_back({v, mid, -cost / 2});
    res.push_back({u, v, -cost / 2});
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        E.push_back({u, v, cost});
    }
    for(int i = 0; i < n; i++) if(G[i].size() == 2) return cout << "NO" << endl, 0;
    cout << "YES" << "\n";
    for(auto e : E) {
        P p1 = get_leaf(e.u, e.v), p2 = get_leaf(e.v, e.u);
        int cost = e.cost;
        if(p1.x == e.u && p2.x == e.v) {
            res.push_back({p1.x, p2.x, cost});
        }
        else if(p1.x == e.u || p2.x == e.v) {
            if(p2.x == e.v) swap(p1, p2);
            res.push_back({p2.x, p2.y, -cost / 2});
            res.push_back({p2.x, p1.x, cost / 2});
            res.push_back({p2.y, p1.x, cost / 2});
        }
        else {
            diff(p1.x, p1.y, p2.x, cost);
            diff(p2.x, p2.y, p1.x, cost);
            res.push_back({p1.y, p2.y, cost});
        }
    }
    cout << res.size() << "\n";
    for(auto e : res) cout << e.u + 1 << " " << e.v + 1 << " " << e.cost << "\n";

}