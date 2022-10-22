#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = N * 30;
const int LOG = 30;


int sum(int a, int b) {
    a += b;
    if(a >= M)
        a -= M;
    return a;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return mul(mul(pw, pw), n);
    else
        return mul(pw, pw);
}

int inv[N];
int C[N][N];
int inv2[N];
int res[N][N];

vector<int> g[N];
int sz[N];

void dfs1(int v, int par) {
    sz[v] = 1;
    for(auto u : g[v])
        if(u != par) {
            dfs1(u, v);
            sz[v] += sz[u];
        }
}

int ans = 0;

vector<int> path;
int root;

void dfs2(int v, int par) {
    path.push_back(v);
    if(v < root) {
        ans = sum(ans, mul(sz[root] - sz[path[1]], inv[sz[root]]));
//        cout << "dfs2 " << root << ' ' << v << ' ' << ld(sz[root] - sz[path[1]]) / sz[root] << endl;
        for(int i = 1; i < path.size() - 1; i++) {
            ans = sum(ans, mul(mul(sz[path[i]] - sz[path[i + 1]], inv[sz[root]]), res[i][path.size() - i - 1]));
                               //mul(path.size() - i - 1, inv[path.size() - 1])));
//            cout << "dfs2 for " << ' ' << root << ' ' << v << ' ' << path[i] << ' ' <<
//            ld(sz[path[i]] - sz[path[i + 1]]) / sz[root] * (path.size() - i - 1) / (path.size() - 1) << endl;
//            mul(mul(sz[path[i]] - sz[path[i + 1]], inv[sz[root]]), mul(path.size() - i - 1, inv[path.size()])) << endl;
        }
    }

    for(auto u : g[v])
        if(u != par)
            dfs2(u, v);

    path.pop_back();
}



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

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

    int pw2 = 1;
    for(int i = 0; i < N; i++) {
        inv[i] = pow2(i, M - 2);
        inv2[i] = pow2(pw2, M - 2);
        pw2 = mul(pw2, 2);
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }

    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            res[x][y] = 0;
            for(int i = x; i < x + y; i++) {
                res[x][y] = sum(res[x][y], mul(C[i - 1][x - 1], inv2[i]));
            }
        }
    }

    for(root = 0; root < n; root++) {
        dfs1(root, -1);
        dfs2(root, -1);
//        cout << root <<' ' << ans << endl;
    }

    cout << ans << endl;
}