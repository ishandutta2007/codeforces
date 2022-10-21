#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1005, M = 5005, INF = (int)1e9;


struct edge {
    int to, cost, id;
};

int res[M];
int n, m;
int dis[N];
vector<edge> G[N];
int r0[N], rn[N];

void dfs0(int v) {
    r0[v] = 1;
    for(auto e : G[v]) if(e.cost > 0 && !r0[e.to]) dfs0(e.to);
}

void dfsn(int v) {
    rn[v] = 1;
    for(auto e : G[v]) if(e.cost < 0 && !rn[e.to]) dfsn(e.to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, 2, i});
        G[b].push_back({a, -1, -1});
    }

    dfs0(0);
    dfsn(n - 1);
    fill(dis, dis + n, INF);
    dis[0] = 0;
    rep(it, 0, n + 1) {
        bool up = false;
        rep(i, 0, n) {
            if(!r0[i] || !rn[i]) continue;
            for(auto e : G[i]) {
                if(dis[e.to] > dis[i] + e.cost) {
                    dis[e.to] = dis[i] + e.cost;
                    up = true;
                }
            }
        }
        if(it == n && up) return cout << "No" << endl, 0;
    }
    rep(i, 0, n) {
        for(auto e : G[i]) {
            if(e.id != -1) res[e.id] = dis[e.to] - dis[i];
        }
    }
    cout << "Yes\n";
    rep(i, 0, m) {
        if(res[i] != 1 && res[i] != 2) res[i] = 1;
        cout << res[i] << '\n';
    }


}