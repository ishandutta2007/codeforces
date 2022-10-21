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

struct edge {
    int to, tp;
};
int n, m;
vector<edge> G[N * 2];



vi H[N * 2];

void add_edge(int u, int v, int tp) {
    G[u].push_back({v, tp});
    G[v].push_back({u, tp});
}

int in[N];
int ori[N], vis[N];
int res[N];

void dfs(int v, int tor) {
    ori[v] = tor;
    for (auto &e : G[v]) {
        int nxttor;
//            = !(e.tp ^ tor);
        if(e.tp == 0) {
            if(tor == 0) H[v].push_back(e.to), nxttor = 1;
            else H[e.to].push_back(v), nxttor = 0;
        } else {
            if(tor == 1) H[v].push_back(e.to), nxttor = 0;
            else H[e.to].push_back(v), nxttor = 1;
        }

        if(ori[e.to] == -1) {
            dfs(e.to, nxttor);
        } else {
            if(ori[e.to] != nxttor) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int tp, u, v; cin >> tp >> u >> v;
        u--, v--; tp--;
        add_edge(u, v, tp);
    }
    memset(ori, -1, sizeof(ori));
    rep(i, 0, n) {
        if(ori[i] == -1) dfs(i, 0);
    }
    queue<int> que;
    rep(i, 0, n) for (int nxt : H[i]) in[nxt]++;

    memset(res, -1, sizeof(res));
    int cx = 0;

    rep(i, 0, n) {
        if(in[i] == 0) {
            que.push(i);
            res[i] = cx++;
        }
    }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for (int nxt : H[v]) {
            if(--in[nxt] == 0) {
                que.push(nxt);
                res[nxt] = cx++;
            }
        }
    }
    rep(i, 0, n) if(res[i] == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    rep(i, 0, n) {
        cout << (ori[i] ? "R" : "L") << " " << res[i] << "\n";
    }


}