#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(degug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
2 3
1 2
*/

pii e[N];
vector<int> g[N];
int ans[N];

void dfs(int v, int par, bool cur) {
    for(auto ed : g[v]) {
        int u = e[ed].f ^ e[ed].s ^ v;
        if(u == par)
            continue;

        ans[ed] = (cur ? 2 : 3);
        dfs(u, v, !cur);
    }
}

void solve(bool debug_out) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        ans[i] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(i);
        g[u].push_back(i);
        e[i] = {v, u};
    }

    int root = -1;
    for(int i = 0; i < n; i++) {
        if(g[i].size() > 2) {
            cout << -1 << endl;
            return;
        } else if(g[i].size() == 1)
            root = i;
    }

    dfs(root, -1, true);

    for(int i = 0; i < n - 1; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve(true);
}