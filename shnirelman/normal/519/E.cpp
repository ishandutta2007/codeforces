//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 100;
const int A = 26;
const int K = 400;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

vector<int> g[N];
int tin[N], tout[N], d[N], sz[N];
int T = 1;

int p[N][LOGN];

void dfs1(int v, int par, int depth) {
    tin[v] = T++;
    d[v] = depth;
    sz[v] = 1;

    p[v][0] = par;
    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }

    for(auto u : g[v]) {
        if(u != par) {
            dfs1(u, v, depth + 1);
            sz[v] += sz[u];
        }
    }

    tout[v] = T++;
}

bool is_anc(int anc, int v) {
    return (tin[anc] <= tin[v] && tout[v] <= tout[anc]);
}

int lca(int v, int u) {
    if(is_anc(v, u))
        return v;
    if(is_anc(u, v))
        return u;

    for(int k = LOGN - 1; k >= 0; k--)
        if(!is_anc(p[v][k], u))
            v = p[v][k];

    return p[v][0];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, 0, 0);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        int ans = 0;

        if(d[v] == d[u]) {
            if(v == u) {
                ans = n;
            } else {
                for(int k = LOGN - 1; k >= 0; k--) {
                    if(p[v][k] != p[u][k]) {
                        v = p[v][k];
                        u = p[u][k];
                    }
                }
                ans = n - sz[v] - sz[u];
            }
        } else {
            if(d[v] < d[u])
                swap(v, u);

            if((d[v] + d[u]) % 2 == 1) {
                ans = 0;
            } else {
                int w = lca(v, u);
                int depth = (d[w] * 2 + d[v] - d[u]) / 2;
//                cout << v << ' ' << u << ' ' << depth << ' ' << w << endl;
                for(int k = LOGN - 1; k >= 0; k--)
                    if(d[v] - (1 << k) > depth)
                        v = p[v][k];

//                cout << "v " << v << endl;

                ans = sz[p[v][0]] - sz[v];
            }
        }

        cout << ans << '\n';
    }
}