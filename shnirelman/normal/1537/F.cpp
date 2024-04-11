#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int p = 43;
const int N = 2e5 + 13;

vector<int> g[N];
int col[N];
li s = 0;
bool is = false;

int a[N], b[N];

void dfs(int v, int cl) {
    col[v] = cl;
    s += (b[v] - a[v]) * (cl == 0 ? 1 : -1);

    for(auto u : g[v])
        if(col[u] == -1)
            dfs(u, cl ^ 1);
        else if(col[u] == cl)
            is = true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        col[i] = -1;
    }
    s = 0;
    is = false;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];


    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    cout << (is && s % 2 == 0 || s == 0 ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}