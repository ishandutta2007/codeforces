#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;
const int MAXL = 18;

int N, M;
pair<int, int> edge[MAXN];
vector<pair<int, ll>> adj[MAXN];

ll edge_up[MAXN];
int depth[MAXN];
int par[MAXN][MAXL];

void fill(int loc, int abv) {
    par[loc][0] = abv;
    for (int l = 1; l < MAXL; l++)
        par[loc][l] = par[par[loc][l-1]][l-1];

    for (auto v : adj[loc]) {
        if (v.first == abv) continue;

        depth[v.first] = depth[loc] + 1;
        edge_up[v.first] = v.second;

        fill(v.first, loc);
    }
}

int go_up(int loc, int far) {
    for (int l = 0; l < MAXL; l++)
        if ((far >> l) & 1)
            loc = par[loc][l];
    return loc;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = go_up(a, depth[a] - depth[b]);
    if (a == b) return a;

    for (int l = MAXL - 1; l >= 0; l--) {
        if (par[a][l] != par[b][l]) {
            a = par[a][l];
            b = par[b][l];
        }
    }

    return par[a][0];
}

struct union_find{
    vector<int> P, R, S;
    vector<pair<int, int>> SM;
    
    union_find(int N){
        P.resize(N), R.resize(N), S.resize(N), SM.resize(N);
        for(int i=0; i<N; i++){
            P[i] = i;
            R[i] = 0;
            S[i] = 1;
            SM[i] = make_pair(depth[i], i);
        }
    }
    
    int rep(int i){
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b){
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;

        if (SM[b].first < SM[a].first)
            SM[a] = SM[b];

        return true;
    }
};

ll solve(union_find &uf, int a, int b, ll V) {
    int p = lca(a, b);

    while (V > 0) {
        int ra = uf.rep(a);
        a = uf.SM[ra].second;

        if (depth[a] <= depth[p]) break;
        V /= edge_up[a];
        a = par[a][0];
    }

    while (V > 0) {
        int rb = uf.rep(b);
        b = uf.SM[rb].second;

        if (depth[b] <= depth[p]) break;
        V /= edge_up[b];
        b = par[b][0];
    }

    return V;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int &u = edge[i].first;
        int &v = edge[i].second;
        ll c;

        cin >> u >> v >> c;
        u--, v--;

        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    fill(0, 0);

    union_find uf(N);

    for (int i = 1; i < N; i++) {
        if (edge_up[i] == 1) {
            uf.unio(i, par[i][0]);
        }
    }

    int T, A, B, P;
    ll Y, C;

    for (int i = 0; i < M; i++) {
        cin >> T;
        if (T == 1) {
            cin >> A >> B >> Y;
            cout << solve(uf, A - 1, B - 1, Y) << "\n";
        } else {
            cin >> P >> C;
            P--;
            int u = edge[P].first;
            int v = edge[P].second;

            if (depth[u] > depth[v]) swap(u, v);
            edge_up[v] = C;
            if (C == 1) uf.unio(u, v);
        }
    }
}