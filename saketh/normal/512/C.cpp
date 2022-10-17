#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _for(i, a, b) for (__typeof__(a) i = (a); i != (b); ++i)
#define foreach(x...) _for(x)
#define forall(i, v) foreach(i, all(v))
#define FU(i, a, b) for(__typeof__(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)
#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-1;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct graph {
    int _ini, _end, delta;
    vi dest, cap, flow, imb;
    vd cost, pot;
    vvi adj;

    int inv(int a) { return a ^ 0x1; }
    
    graph(int n = 0) {
        _ini = _end = -1;
        adj.resize(n);
        imb.resize(n);
    }

    int arc(int i, int j, int u = 0, double c = 0) {
        dest.pb(j);
        adj[i].pb(sz(dest)-1);
        dest.pb(i);
        adj[j].pb(sz(dest)-1);
        cap.pb(u);
        cap.pb(0);
        cost.pb(c);
        cost.pb(-c);
        return sz(dest)-2;
    }

    int orig(int a){ return dest[inv(a)]; }
    int capres(int a){ return cap[a] - flow[a]; }

    vi d, curAdj;

    bool MFbfs(int s, int t) {
        d = vi(sz(adj), INF);
        curAdj = vi(sz(adj));
        d[s] = 0;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            forall(i, adj[u]) {
                int v = dest[*i];
                if (capres(*i) > 0 && d[v] == INF) {
                    d[v] = d[u] + 1; Q.push(v);
                }
            }
        }
        return d[t] != INF;
    }

    int MFdfs(int u, int t, int f) {
        if (u == t) return f;
        for(int &i = curAdj[u]; i < adj[u].size(); ++i) {
            int ar = adj[u][i], v = dest[ar];
            if (d[v] != d[u]+1 || capres(ar) == 0) continue;
            int tmpF = MFdfs(v, t, min(f, capres(ar)));
            if (tmpF) {
                flow[ar] += tmpF;
                flow[inv(ar)] -= tmpF;
                return tmpF;
            }
        }
        return 0;
    }

    int maxflow(int ini, int end) {
        if (_ini != ini || _end != end) {
            flow = vi(sz(dest));
            _ini = ini;
            _end = end;      
        }
        while (MFbfs(ini, end))
            while (MFdfs(ini, end, INF));
        int F = 0;
        forall(a, adj[ini]) F += flow[*a];
        return F;
    }    
};

void fail() {
    cout << "Impossible\n";
    exit(0);
}

const int MAXV = 2e4 + 200;
int sieve[MAXV];

int N, V;
vector<int> odd, even;
vector<int> odd_idx, even_idx;

vector<int> adj[256];

bool visit[256];

vector<int> seq;
void dfs(int loc) {
    if(visit[loc]) return;
    visit[loc] = true;
    seq.push_back(loc);
    for (int nbr : adj[loc]) dfs(nbr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q+=p) 
            sieve[q] = p;
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> V;

        if(V&1) {
            odd.push_back(V);
            odd_idx.push_back(i);
        }
        else {
            even.push_back(V);
            even_idx.push_back(i);
        }
    }

    if (odd.size() != even.size()) fail();

    graph g(N + 2);
    const int source = 0, sink = N + 1;

    for (int i = 1; i <= N; i++) {
        if (i <= N / 2) g.arc(source, i, 2);
        else g.arc(i, sink, 2);
    }

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int sum = odd[i] + even[j];
            if (sieve[sum] != sum) continue;
            g.arc(i + 1, j + 1 + N / 2, 1);
        }
    }

    int flow = g.maxflow(source, sink);

    if (flow != N) fail();

    for (int i = 0; i < N / 2; i++) {
        for (int e : g.adj[i+1]) {
            if(g.flow[e] && g.dest[e] > 0) {
                adj[i].push_back(g.dest[e] - 1);
                adj[g.dest[e] - 1].push_back(i);
            }            
        }
    }

    vector<vector<int>> res;

    for (int i = 0; i < N; i++) {
        if (visit[i]) continue;
        seq.clear();
        dfs(i);
        res.push_back(seq);
    }

    cout << res.size() << "\n";
    for (auto &v : res) {
        cout << v.size() << " ";
        for (int i : v) {
            if (i < N / 2) cout << odd_idx[i] + 1 << " ";
            else cout << even_idx[i - N/2] + 1 << " ";
        }
        cout << "\n";
    }
}