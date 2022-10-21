#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

int n, m;
vector<pii> G[N];
bool vis[N];
pii p[N];
vector<pii> res;

void dfs(int v, int back_v = -1){
    while(G[v].size()){
        auto e = G[v].back(); G[v].pop_back();
        if(vis[e.second]) continue;
        vis[e.second] = true;
        dfs(e.first, v);
    }
    if(back_v != -1) {
        res.push_back({v, back_v});
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        p[i] = {a, b};
    }
    int la = -1;
    rep(i, 0, n) {
        if(sz(G[i]) % 2 == 1) {
            if(la == -1) la = i;
            else {
                G[la].push_back({i, m});
                G[i].push_back({la, m});
                p[m++] = {i, la};
                la = -1;
            }
        }
    }
    if(m % 2 == 1) {
        G[0].push_back({0, m});
        p[m++] = {0, 0};
    }
    dfs(0, -1);
    cout << m << '\n';
    assert(sz(res) == m);
    rep(i, 0, m) {
        if(i % 2 == 1) swap(res[i].first, res[i].second);
        cout << res[i].first + 1 << " " << res[i].second + 1 << '\n';
    }


}