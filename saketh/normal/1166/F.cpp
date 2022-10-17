#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct union_find {
    vi P, R, S;
    vector<set<int>> adj;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
        adj.resize(N);
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if (adj[a].size() < adj[b].size()) {
            swap(adj[a], adj[b]);
        }
        for (int v : adj[b])
            adj[a].insert(v);
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, Q;
    cin >> N >> M >> C >> Q;

    union_find uf(N);
    vector<map<int, int>> adj(N);

    auto insert = [&](int u, int v, int c) {
        uf.adj[uf.rep(u)].insert(v);
        uf.adj[uf.rep(v)].insert(u);

        if (adj[u].count(c)) {
            uf.unio(adj[u][c], v);
        } else {
            adj[u][c] = v;
        }

        if (adj[v].count(c)) {
            uf.unio(adj[v][c], u);
        } else {
            adj[v][c] = u;
        }
    };

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        insert(u-1, v-1, c);
    }

    for (int q = 0; q < Q; q++) {
        char op;
        cin >> op;
        if (op == '+') {
            int u, v, c;
            cin >> u >> v >> c;
            insert(u-1, v-1, c);
        } else {
            int u, v;
            cin >> u >> v;
            bool reach = uf.rep(u-1) == uf.rep(v-1)
                       || uf.adj[uf.rep(u-1)].count(v-1);
            cout << (reach ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}