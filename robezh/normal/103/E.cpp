#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 606, INF = (int)1e9 + 50;

struct Flow {
    struct edge{
        int to, cap, rev;
        edge(int _to, int _cap, int _rev){
            to = _to, cap = _cap, rev = _rev;
        }
    };

    vector<vector<edge> > G;
    vector<int> used;
    Flow(int n) : G(n), used(n) {}

    void add_edge(int from, int to, int cap){
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        used[v] = true;

        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int f = 0;
        for(;;){
            fill(used.begin(), used.end(), 0);
            int d = dfs(s, t, INF);
            if(d == 0) return f;
            f += d;
        }
    }
};

int n;
int val[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    Flow bip(2 * n + 2);
    int s = 2 * n, t = s + 1;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        bip.add_edge(s, i, 1);
        bip.add_edge(i + n, t, 1);
        for(int j = 0; j < k; j++) {
            int x; cin >> x; x--;
            bip.add_edge(i, x + n, 1);
        }
    }
    for(int i = 0; i < n; i++) cin >> val[i], val[i] = -val[i];
    assert(bip.max_flow(s, t) == n) ;
    vi match(n, -1);
    for(int i = 0; i < n; i++) {
        trav(e, bip.G[i]) {
            if(e.to != s && e.cap == 0) {
                match[e.to - n] = i;
            }
        }
    }
    Flow clo(n + 2);
    int cs = n, ct = n + 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(val[i] >= 0) sum += val[i], clo.add_edge(cs, i, val[i]);
        else clo.add_edge(i, ct, -val[i]);

        trav(e, bip.G[i]) {
            if(e.to != s && e.cap == 1) {
                clo.add_edge(i, match[e.to - n], INF);
            }
        }
    }
    cout << -(sum - clo.max_flow(cs, ct)) << '\n';
}