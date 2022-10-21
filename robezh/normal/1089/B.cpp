#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 305;
int n, m;

template<int SZ> struct match {
    int vis[SZ], par[SZ], orig[SZ], match[SZ], aux[SZ], t, N; // 1-based index
    vi adj[SZ];
    queue<int> Q;

    void addEdge(int u, int v) {
        assert(u && v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int n) {
        N = n; t = 0;
        rep(i,0,N+1) {
            adj[i].clear();
            match[i] = aux[i] = par[i] = 0;
        }
    }

    void augment(int u, int v) {
        int pv = v, nv;
        do {
            pv = par[v]; nv = match[pv];
            match[v] = pv; match[pv] = v;
            v = nv;
        } while(u != pv);
    }

    int lca(int v, int w) {
        ++t;
        while (1) {
            if (v) {
                if (aux[v] == t) return v; aux[v] = t;
                v = orig[par[match[v]]];
            }
            swap(v, w);
        }
    }

    void blossom(int v, int w, int a) {
        while (orig[v] != a) {
            par[v] = w; w = match[v];
            if (vis[w] == 1) Q.push(w), vis[w] = 0;
            orig[v] = orig[w] = a;
            v = par[w];
        }
    }

    bool bfs(int u) {
        fill(vis+1, vis+1+N, -1); iota(orig + 1, orig + N + 1, 1);
        Q = queue<int> (); Q.push(u); vis[u] = 0;
        while (sz(Q)) {
            int v = Q.front(); Q.pop();
            trav(x,adj[v]) {
                if (vis[x] == -1) {
                    par[x] = v; vis[x] = 1;
                    if (!match[x]) return augment(u, x), true;
                    Q.push(match[x]); vis[match[x]] = 0;
                } else if (vis[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v], orig[x]);
                    blossom(x, v, a); blossom(v, x, a);
                }
            }
        }
        return false;
    }

    int Match() {
        int ans = 0;
        // find random matching (not necessary, constant improvement)
        vi V(N-1); iota(all(V), 1);
        shuffle(all(V), mt19937(233333));
        trav(x,V) if(!match[x])
            trav(y,adj[x]) if (!match[y]) {
            match[x] = y, match[y] = x;
            ++ans; break;
        }

        rep(i,1,N+1) if (!match[i] && bfs(i)) ++ans;
        return ans;
    }
};

match<305> mc;
string str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> str[i];
        mc.init(n * 2 + m);
        rep(i, 0, n) {
            mc.addEdge(i + 1 + m, i + 1 + m + n);
            rep(j, 0, m) {
                if(str[i][j] == '1') {
                    mc.addEdge(i + 1 + m, j + 1);
                    mc.addEdge(i + 1 + m + n, j + 1);
                }
            }
        }
        cout << mc.Match() - n << '\n';
    }
}