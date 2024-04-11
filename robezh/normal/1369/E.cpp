#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e5 + 50;

struct edge {
    int to, id;
};

int n, m;
int rem[N];
vi ord;
int vis[N];
vector<edge> G[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    queue<int> que;
    rep(i, 0, n) cin >> rem[i];
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        rem[u]--, rem[v]--;
    }
    rep(i, 0, n) {
        if(rem[i] >= 0) {
            que.push(i);
            ord.push_back(i);
        }
    }
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(auto e : G[u]) {
            if(rem[e.to] < 0) {
                rem[e.to]++;
                if(rem[e.to] == 0) {
                    que.push(e.to);
                    ord.push_back(e.to);
                }
            }
        }
    }
    if(sz(ord) != n) return cout << "DEAD\n", 0;
    reverse(all(ord));
    fill(vis, vis + n, 0);
    vector<int> res;
    for(int i : ord) {
        vis[i] = 1;
        for(auto e : G[i]) {
            if(vis[e.to]) res.push_back(e.id);
        }
    }
    cout << "ALIVE\n";
    for(int x : res) cout << x + 1 << " ";
    cout << '\n';

}