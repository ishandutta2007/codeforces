#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 605, INF = (int)2e9;
struct edge {
    int to, c;
};


int n, m;
vector<edge> G[N];
int res[N][N];
int in[N][N];
int vis[N];
int dis[N];


void calc(int s) {
    int mnc = INF;
    for (auto &e : G[s]) mnc = min(mnc, e.c);
    memset(in, 0, sizeof(in));

//    cout << s << endl;

    fill(dis, dis + n, INF);
    fill(vis, vis + n, 0);
    for(auto &e : G[s]) {
        if(e.c < mnc + n) {
            in[e.c - mnc][e.to] = 1;
            dis[e.to] = e.c - mnc;
//            cout << e.to << ": " << dis[e.to] << endl;
        }
    }

    auto upd = [&](int v, int d) {
        if(d < n && d < dis[v]) {
            dis[v] = d;
            in[d][v] = 1;
        }
    };
    rep(d, 0, n) {
        rep(v, 0, n) {
            if(!vis[v] && in[d][v]) {
                vis[v] = 1;
//                cout << v << ": " << dis[v] << endl;
                upd((v + 1) % n, d + 1);
                for (auto &e : G[v]) {
                    upd((e.to + mnc + d) % n, d + e.c);
                }
            }
        }
    }
    rep(i, 0, n) {
        if(i == s) res[s][i] = 0;
        else res[s][i] = dis[i] + mnc;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    rep(i, 0, n) calc(i);
    rep(i, 0, n) {
        rep(j, 0, n) cout << res[i][j] << " ";
        cout << '\n';
    }


}