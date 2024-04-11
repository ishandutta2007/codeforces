#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;

int p[N];
vector<int> g[N];
int sz[N], mx[N];
int res[N];

void dfs(int v) {
    sz[v] = 1;
    mx[v] = -1;

    if(g[v].empty()) {
        res[v] = v;
        return;
    }

    for(auto u : g[v]) {
        dfs(u);
        sz[v] += sz[u];
        if(mx[v] == -1 || sz[mx[v]] < sz[u])
            mx[v] = u;
    }

    if(sz[mx[v]] * 2 <= sz[v]) {
        res[v] = v;
        return;
    }

    int u = res[mx[v]];
    while((sz[v] - sz[u]) * 2 > sz[v]) {
        u = p[u];
    }

    res[v] = u;
}


int main() {
    int n, q;
    cin  >> n >> q;

    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;

        g[p[i]].push_back(i);
    }

    dfs(0);

    for(int i = 0; i < q; i++) {
        int v;
        cin >> v;

        cout << res[v - 1] + 1 << endl;
    }

}