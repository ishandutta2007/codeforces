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

int n, m, k;
int comp[N], in_com[N];
int in_com_cnt[N];
int gbad[N];
int par[N];
int vis[N];
vi G[N];
map<pii, vector<pii> > es;

void dfs(int v, int cur_com) {
    in_com[v] = cur_com;
    vis[v] = 1;
    for(int nxt : G[v]) {
        if(comp[nxt] != comp[v]) continue;
        if(vis[nxt] && par[nxt] != (par[v] ^ 1)) {
            gbad[comp[v]] = 1;
        }
        if(vis[nxt]) continue;;
        par[nxt] = par[v] ^ 1;
        dfs(nxt, cur_com);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) cin >> comp[i], comp[i]--;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(i, in_com_cnt[comp[i]]++);
    }
    for(int a = 0; a < n; a++) {
        for(int b : G[a]) {
            if(a < b && comp[a] != comp[b]) {
                int ca = comp[a], cb = comp[b];
                if(ca > cb) swap(ca, cb);
                es[{ca, cb}].push_back({a, b});
//                cout << ca << " and " << cb << endl;
            }
        }
    }


    int ck = 0;
    for(int i = 0; i < k; i++) ck += !gbad[i];

    ll res = 1LL * ck * (ck - 1) / 2;

    for(auto &p : es) {
        if(gbad[p.first.first] || gbad[p.first.second]) continue;
        map<int, vector<pii> > to;

        map<pii, int> idxs;
        int curidx = n;

//        cout << p.first.first << ", " << p.first.second << endl;
        for(auto &eg : p.second) {
            pii curcp = {comp[eg.first], in_com[eg.first]};
            if(!idxs.count(curcp)) idxs[curcp] = curidx++;
            to[eg.first].push_back({idxs[curcp], par[eg.first]});
            to[idxs[curcp]].push_back({eg.first, par[eg.first]});

            curcp = {comp[eg.second], in_com[eg.second]};
            if(!idxs.count(curcp)) idxs[curcp] = curidx++;
            to[eg.second].push_back({idxs[curcp], par[eg.second]});
            to[idxs[curcp]].push_back({eg.second, par[eg.second]});

            to[eg.first].push_back({eg.second, 1});
            to[eg.second].push_back({eg.first, 1});
        }

        int good = 1;
        map<int, int> done;
        function<void(int, int)> dfs = [&](int v, int color) {
            done[v] = color;
            for(auto &e : to[v]) {
                if(done[e.first]) {
                    if(done[e.first] != (color ^ e.second)) {
                        good = 0;
                    }
                    continue;
                }
                dfs(e.first, color ^ e.second);
            }
        };
        for(auto &p : to) {
            if(!done[p.first]) dfs(p.first, 2);
        }
        if(!good) res--;

    }

    cout << res << '\n';

}