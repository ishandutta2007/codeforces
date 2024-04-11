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

const int N = 1005, mod = 998244353;

set<pii> S[N];
int n, vis[N];
int in[N];
int a[N][N];
map<int, set<int> > mp[N];
vi G[N];
int col[N];
vi vs;

bool dfs(int v, int c) {
    col[v] = c;
    if(c == 0) vs.push_back(v);
    bool res = true;
    for (int nxt : G[v]) {
        if(col[nxt] == -1) {
            res &= dfs(nxt, !c);
        } else {
            res &= col[nxt] == !c;
        }
    }
    return res;
}


void del(int idx) {
    rep(j, 0, n) {
        int v = a[idx][j];
        S[j].erase({sz(mp[j][v]), v});
        mp[j][v].erase(idx);
        if(sz(mp[j][v])) S[j].insert({sz(mp[j][v]), v});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) S[i].clear(), mp[i].clear();
        rep(i, 0, 2 * n) {
            rep(j, 0, n) {
                cin >> a[i][j];
                mp[j][a[i][j]].insert(i);
            }
        }
        rep(j, 0, n) {
            for (auto &p: mp[j]) S[j].insert({sz(p.second), p.first});
        }
        fill(vis, vis + 2 * n, -1);
        vs.clear();
        while(true) {
            int jdx = -1;
            rep(j, 0, n) if(!S[j].empty() && S[j].begin() -> first == 1) jdx = j;
            if(jdx == -1) {
                break;
            }
            auto it = S[jdx].begin();
            int idx = *mp[jdx][it -> second].begin();

            vs.push_back(idx);
            set<int> ds;
            rep(j, 0, n) {
                for (int x : mp[j][a[idx][j]]) {
                    ds.insert(x);
                }
            }

            vis[idx] = 1;
            for (int x : ds) {
                if(x != idx) vis[x] = 0;
                del(x);
            }
        }
        rep(i, 0, 2 * n) G[i].clear();
        rep(j, 0, n) {
            for (auto &p : S[j]) {
//                cout << j << ": " << p.firs/**/t << " " << p.second << endl;
                assert(p.first == 2);
                auto i2 = mp[j][p.second].begin();
                auto i1 = i2++;
                G[*i2].push_back(*i1);
                G[*i1].push_back(*i2);
                assert(vis[*i1] == -1 && vis[*i2] == -1);
            }
        }
        fill(col, col + 2 * n, -1);
        ll res = 1;

        rep(i, 0, 2 * n) {
            if(vis[i] == -1 && col[i] == -1) {
                bool rs = dfs(i, 0);
                assert(rs);
                res = (res * 2) % mod;
            }
        }
        cout << res << '\n';
        sort(all(vs));
        for (int x : vs) cout << x + 1 << " ";
        cout << '\n';
    }


}