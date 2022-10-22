#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

vector<int> g[N];
int sz[N];

void dfs1(int v, int par) {
    sz[v] = 1;
    for(int u : g[v]) {
        if(u != par) {
            dfs1(u, v);
            sz[v] += sz[u];
        }
    }
}

int dfs2(int v, int par) {
    int sum = 0;
    int cnt = 0;
    for(int u : g[v]) {
        if(u != par) {
            sum += sz[u];
            cnt++;
        }
    }

//    cout << "dfs2 " << v << ' ' << mx << endl;

    int res = 0;
    if(cnt <= 1) {
        res = max(0, sum - 1);
    } else {
        for(int u : g[v]) {
            if(u != par) {
                res = max(res, dfs2(u, v) + max(0, sum - sz[u] - 1));
            }
        }

    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
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

//    for(int i = 0; i < n; i++)
//        cout << sz[i] << ' ';
//    cout << endl;

    cout << dfs2(0, -1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}