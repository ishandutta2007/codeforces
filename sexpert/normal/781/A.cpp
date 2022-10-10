#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int deg[MAXN], col[MAXN];

void dfs(int s, int p, int c) {
    col[s] = c;
    int pcol = col[p], ccol = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        while(ccol == pcol || ccol == c)
            ccol++;
        dfs(v, s, ccol++);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ma = 0, mv = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] > ma) {
            ma = deg[i];
            mv = i;
        }
    }
    dfs(mv, 0, 1);
    cout << ma + 1 << '\n';
    for(int i = 1; i <= n; i++)
        cout << col[i] << " ";
    cout << '\n';
}