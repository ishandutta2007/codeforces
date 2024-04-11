#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 2005;
const ll INF = (ll)1e18;

struct edge{
    int u, v, cost;
};
int n;
int e[N][N];
ll dis[N];
int vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll min_e = INF;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            cin >> e[i][j];
            e[j][i] = e[i][j];
            min_e = min(min_e, (ll)e[i][j]);
        }
    }
    rep(i, 0, n) {
        dis[i] = INF;
        rep(j, 0, n) {
            if(i != j) dis[i] = min(dis[i], 2LL * (e[i][j] - min_e));
        }
    }
    rep(it, 0, n) {
        int v = -1;
        rep(j, 0, n) if(!vis[j] && (v == -1 || dis[j] < dis[v])) v = j;
        vis[v] = 1;
        rep(nxt, 0, n) {
            if(nxt != v) dis[nxt] = min(dis[nxt], dis[v] + (e[v][nxt] - min_e));
        }
    }
    rep(i, 0, n) cout << dis[i] + (n - 1) * min_e << "\n";
//    cout << '\n';


}