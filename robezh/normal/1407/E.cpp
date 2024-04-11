#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50, INF = (int)1e9;

struct edge {
    int to, c;
};

int n, m;
vector<edge> G[N];
int d[N][2], res[N];

set<pii> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        G[v].push_back({u, c});
    }
    for(int i = 0; i < n; i++) d[i][0] = d[i][1] = res[i] = INF;
    d[n - 1][0] = d[n - 1][1] = res[n - 1] = 0;
    queue<int> que;
    que.push(n - 1);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(auto &e : G[v]) {
            if(max(d[e.to][0], d[e.to][1]) > res[v] + 1) {
                d[e.to][e.c] = min(d[e.to][e.c], res[v] + 1);
                if(max(d[e.to][0], d[e.to][1]) == res[v] + 1) {
                    res[e.to] = res[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    cout << (res[0] == INF ? -1 : res[0]) << '\n';
    rep(i, 0, n) {
        cout << (d[i][1] > d[i][0]);
    }
    cout << '\n';

}