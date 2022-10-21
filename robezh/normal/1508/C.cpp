#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50, INF = (1 << 30) + 2;

int n, m;
set<int> S;
map<pii, int> con;

struct edge {
    int a, b, w, vis;
};

struct ek {
    int to, x;
};

vector<edge> es;
vector<ek> G[N];

int f[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void unite(int u, int v) {
    f[find(u)] = find(v);
}

void dfs(int v) {
//    cout << v << endl;
    S.erase(v);
    auto it = S.begin();
    int curv = -1;
    while(!S.empty()) {
//        assert(!S.empty());
        auto it = S.lower_bound(curv);
        if(it == S.end()) break;
        int nxt = *it;
        curv = nxt + 1;
        if(!con[{nxt, v}]) {
            if(find(nxt) != find(v)) {
                unite(nxt, v);
                G[v].push_back({nxt, 1});
                G[nxt].push_back({v, 1});
            }
            dfs(nxt);
        }
    }
}

int rs[N];
void solve(int v, int p, int c) {
    rs[v] = c;
    for(auto &e : G[v]) {
        if(e.to != p) {
            solve(e.to, v, max(e.x, c));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    iota(f, f + n, 0);
    int sum = 0;
    rep(i, 0, m) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        sum ^= w;
        con[{a, b}] = con[{b, a}] = 1;
        es.push_back({a, b, w, 0});
    }
//    cout << "xor sum is " << sum << endl;
    sort(all(es), [](const edge &e1, const edge &e2) {
        return e1.w < e2.w;
    });
    rep(i, 0, n) S.insert(i);
    int compcnt = 0;
    while(!S.empty()) {
        dfs(*S.begin());
        compcnt++;
    }
    int use_edge = n - compcnt;
//    cout << "comp: " << compcnt << endl;
    ll fres = 0;
    for(auto &e : es) {
        if(find(e.a) != find(e.b)) {
            fres += e.w;
            G[e.a].push_back({e.b, 0});
            G[e.b].push_back({e.a, 0});
            unite(e.a, e.b);
            e.vis = 1;
        }
    }


    if(use_edge + m ==  1LL * n * (n - 1) / 2) {
//        cout << "tree\n";
        ll me = (ll)1e18;
        for(auto &e : es) {
            if(!e.vis) {
                solve(e.a, -1, 0);
                if(rs[e.b]) {
                    me = min(me, 1LL * e.w);
                }
            }
        }
//        cout << "found " << me << endl;
        fres += min(me, 1LL * sum);
    }
    cout << fres << '\n';


}