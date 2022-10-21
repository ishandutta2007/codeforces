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

const int N = (int)2e5 + 50;

struct edge {
    int to, c;
};

struct Tedge {
    int u, v, c;
} tr[N];
int n, m;
vector<edge> G[N];
int col[N];
bool bad = false;

void dfs(int v, int c) {
    col[v] = c;
    for (auto &e : G[v]) {
        if(col[e.to] == -1) {
            dfs(e.to, c ^ e.c);
        } else if(col[e.to] != (c ^ e.c)) {
            bad = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, n - 1) {
            cin >> tr[i].u >> tr[i].v >> tr[i].c;
            tr[i].u--;
            tr[i].v--;
            if(tr[i].c >= 0) {
                int pr = __builtin_popcount(tr[i].c);
                G[tr[i].u].push_back({tr[i].v, pr % 2});
                G[tr[i].v].push_back({tr[i].u, pr % 2});
            }
        }
        rep(i, 0, m) {
            int s, t, p; cin >> s >> t >> p; s--, t--;
            G[s].push_back({t, p});
            G[t].push_back({s, p});
        }
        fill(col, col + n, -1);
        bad = false;
        rep(i, 0, n) {
            if(col[i] == -1) {
                dfs(i, 0);
            }
        }
        if(bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            rep(i, 0, n - 1) {
                if(tr[i].c >= 0) cout << tr[i].u + 1 << " " << tr[i].v + 1 << " " << tr[i].c << '\n';
                else cout << tr[i].u + 1 << " " << tr[i].v + 1 << " " << (col[tr[i].u] ^ col[tr[i].v]) << '\n';
            }
        }
    }


}