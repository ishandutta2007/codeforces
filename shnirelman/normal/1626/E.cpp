#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

//const bool debug_out = false;
const bool debug_out = true;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

/*
*/

vector<int> g[N];
int c[N];
int cnt[N];
bool is[N];

void dfs1(int v, int par) {
    cnt[v] = c[v];
    is[v] = c[v];

    for(int u : g[v]) {
        is[v] |= (c[u] == 1);

        if(u == par)
            continue;

        dfs1(u, v);

        cnt[v] += cnt[u];
        if(is[u] && cnt[u] > 1)
            is[v] = true;
    }
}

void dfs2(int v, int par) {
    if(par != -1 && is[par] && cnt[0] - cnt[v] > 1) {
        is[v] = true;
    }

    for(int u : g[v]) {
        if(u == par)
            continue;

        dfs2(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, -1);

    dfs2(0, -1);

    for(int i = 0; i < n; i++)
        cout << is[i] << ' ';
    cout << endl;
}