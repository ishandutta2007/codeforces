#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = (int)1e9;

struct SCC {
    vector<vi> G, rG;
    vi vs, used, cmp;

    SCC(int n): G(vector<vi>(n)), rG(vector<vi>(n)), used(vi(n)), cmp(vi(n)) {}

    void init() {
        rep(i, 0, sz(G)) G[i].clear(), rG[i].clear();
        vs.clear();
        fill(all(cmp), 0);
    }

    void add_edge(int from, int to){
//        cout << from << " to " << to << endl;
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for(int nxt : G[v]){
            if(!used[nxt]) dfs(nxt);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for(int nxt : rG[v]){
            if(!used[nxt]) rdfs(nxt, k);
        }
    }

    int scc(){
        fill(all(used), 0);
        vs.clear();
        for(int v = 0; v < sz(G); v++){
            if(!used[v]) dfs(v);
        }
        fill(all(used), 0);
        int k = 0;
        reverse(vs.begin(), vs.end());
        for(int v : vs){
            if(!used[v]) rdfs(v, k++);
        }
        return k;
    }
};


const int N = 2005, M = 160000;

struct Rl {
    int a, ta, b, tb;
    void read() {
        char ca, cb;
        cin >> a >> ca >> b >> cb;
        a--, b--;
        ta = (ca == 'C');
        tb = (cb == 'C');
    }
} r[M];
int len, n, m;
int tp[N];
int all0 = 1, all1 = 1;

struct SAT {
    int n;
    SCC scc;
    SAT(int n): scc(2 * n), n(n) {
    }

    void init() {
        scc.init();
        for(int i = 0; i < m; i++) {
            add_impl(r[i].a, r[i].ta, r[i].b, r[i].tb);
        }
        if(all1 || all0) {
            rep(i, 0, n) enforce_true(i, all1);
        }
    }
    void add_impl(int a, int ta, int b, int tb) {
        scc.add_edge(a + ta * n, b + tb * n);
        ta = !ta, tb = !tb;
        scc.add_edge(b + tb * n, a + ta * n);
    }
    void enforce_true(int a, int ta) {
        scc.add_edge(a + (!ta) * n, a + ta * n);
    }
    bool solve() {
        scc.scc();
        rep(i, 0, n) if(scc.cmp[i] == scc.cmp[i + n]) return false;
        return true;
    }
};

SAT sat(0);

bool trysolve(string str, int l, int r) {
    sat.init();
    for(int i = l; i <= r; i++) {
        sat.enforce_true(i, tp[str[i] - 'a']);
    }
    return sat.solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    len = sz(str);
    rep(i, 0, len) {
        tp[i] = (str[i] == 'C');
        all1 &= (str[i] == 'C');
        all0 &= (str[i] == 'V');
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++) r[i].read();
    cin >> str;

    sat = SAT(n);
    sat.init();
    if(trysolve(str, 0, n - 1)) return cout << str << endl, 0;

    int loc = -1;
    for(int p = n - 1; p >= 0; p--) {
        int fir[2] = {-1, -1};
        for(int j = len - 1; j > (int)(str[p] - 'a'); j--) fir[tp[j]] = j;
        int best = INF;
        for(int j = 0; j < 2; j++) {
            if(fir[j] == -1) continue;
            string nstr = str;
            nstr[p] = (char)('a' + fir[j]);
            if(trysolve(nstr, 0, p)) best = min(best, fir[j]);
        }
        if(best != INF) {
            str[p] = (char)('a' + best);
            loc = p;
            break;
        }
    }
    if(loc == -1) return cout << -1 << endl, 0;
    for(int i = loc + 1; i < n; i++) {
        int fir[2] = {-1, -1};
        for(int j = len - 1; j >= 0; j--) fir[tp[j]] = j;
        int best = INF;
        for(int j = 0; j < 2; j++) {
            if(fir[j] == -1) continue;
            string nstr = str;
            nstr[i] = (char)('a' + fir[j]);
            if(trysolve(nstr, 0, i)) best = min(best, fir[j]);
        }
        assert(best != INF);
        str[i] = (char)('a' + best);
    }
    cout << str << '\n';
}