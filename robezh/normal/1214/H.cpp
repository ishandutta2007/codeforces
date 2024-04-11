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
typedef pair<int, int> P;

const int N = (int)2e5 + 50;

int n, k;
vi G[N];
int dis[2][N], td[N];
int r[N];
int res[N];

void dfs(int v, int p, int d, int *dist) {
    dist[v] = d;
    for (int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v, d + 1, dist);
    }
}

int find_fur(int s) {
    dfs(s, -1, 0, td);
    int v = s;
    rep(i, 0, n) if(td[i] > td[v]) v = i;
    return v;
}

int solve(int v, int p, int cur, int off) {
    res[v] = cur;
    int mx[2] = {0, 0};
    for (int nxt : G[v]) {
        if(r[nxt] == r[v] && nxt != p) {
            int val = solve(nxt, v, (cur + off + k) % k, off);
            rep(i, 0, 2) if(val > mx[i]) swap(val, mx[i]);
        }
    }
    if(k > 2 &&  mx[1] && mx[0] + mx[1] + 1 >= k) {
        cout << "No\n";
        exit(0);
    }
    return mx[0] + 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s = find_fur(0), t = find_fur(s);
    dfs(s, -1, 0, dis[0]);
    dfs(t, -1, 0, dis[1]);
    int rt[2] = {-1, -1};
    rep(i, 0, n) {
        r[i] = dis[0][i] > dis[1][i];
        if(r[i] == 0) {
            if(rt[0] == -1 || dis[1][i] < dis[1][rt[0]]) rt[0] = i;
        } else {
            if(rt[1] == -1 || dis[0][i] < dis[0][rt[1]]) rt[1] = i;
        }
    }
//    cout << s << " " << t << endl;
//    cout << rt[0] << " " << rt[1] << endl;
    solve(rt[0], -1, 1, 1);
    solve(rt[1], -1, 0, -1);

    cout << "Yes\n";
    rep(i, 0, n) {
        cout << res[i] + 1 << " ";
    }
    cout << endl;


}