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
const int N = (int)4e5 + 50;

struct SCC {
    vector<vi> G, rG;
    vi vs, used, cmp;
    int n;
    SCC(int n): G(n), rG(n), vs(n), used(n), cmp(n), n(n) {}

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for(int nxt : G[v]) if(!used[nxt]) dfs(nxt);
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for(int nxt : rG[v]) if(!used[nxt]) rdfs(nxt, k);
    }

    int scc(){
        fill(all(used), 0);
        vs.clear();
        for(int v = 0; v < n; v++) if(!used[v]) dfs(v);
        fill(all(used), 0);
        int k = 0;
        reverse(all(vs));
        for(int v : vs) if(!used[v]) rdfs(v, k++);
        return k;
    }
};

struct TWOSAT {
    int n;
    SCC scc;
    TWOSAT(int n): scc(2 * n), n(n) {

    }
    void add(int x, int v, int y, int v2) {
        scc.add_edge(x + v * n, y + v2 * n);
        scc.add_edge(y + (!v2) * n, x + (!v) * n);
    }

    vi solve() {
        scc.scc();
        vi res;
        rep(i, 0, n) {
            if(scc.cmp[i] == scc.cmp[i + n]) return {-1};
            if(scc.cmp[i] < scc.cmp[i + n]) {
                res.push_back(i);
            }
        }
        return res;
    }

};

int n, p, M, m;
int tl[N], tr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> p >> M >> m;
    TWOSAT sat(p + M);
    rep(i, 0, n) {
        int a, b; cin >> a >> b; a--, b--;
        sat.add(a, 0, b, 1);
    }
    rep(i, 0, p) {
        cin >> tl[i] >> tr[i]; tl[i]--, tr[i]--;
        sat.add(i, 1, p + tl[i], 1);
        if(tr[i] + 1 < M) sat.add(i, 1, p + tr[i] + 1, 0);
    }
    rep(i, 0, M - 1) {
        sat.add(p + i, 0, p + i + 1, 0);
    }
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        sat.add(a, 1, b, 0);
    }
    vi rs = sat.solve();
    if(!rs.empty() && rs[0] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    vi fres;
    int f = -1;
    for(int x : rs) {
        if(x < p) {
            fres.push_back(x);
            f = max(f, tl[x]);
        }
    }
    cout << sz(fres) << " " << f + 1 << '\n';
    for (int x : fres) cout << x + 1 << " ";
    cout << '\n';




}