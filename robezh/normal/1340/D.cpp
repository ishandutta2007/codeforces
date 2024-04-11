#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;

const int N = (int)1e5 + 50;

int n;
vi G[N];
map<int, int> mp[10];
vector<pii> res;
int maxT = 0;

void dfs(int v, int p, int curt) {
    int t = curt;
    int cnt = 0;
    bool back = false;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        if(t == maxT) {
            t = curt - 1 - (sz(G[v]) - (p != -1) - cnt);
            res.push_back({v, t});
            back = true;
        }
        res.push_back({nxt, ++t});
        dfs(nxt, v, t);
        res.push_back({v, t});
        cnt++;
    }
    if(p != -1 && !back) {
        res.push_back({v, curt - 1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n) maxT = max(maxT, sz(G[i]));
    res.push_back({0, 0});
    dfs(0, -1, 0);
    cout << res.size() << '\n';
    for(auto p : res) cout << p.first + 1 << " " << p.second << '\n';
}