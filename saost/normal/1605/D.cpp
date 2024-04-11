#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, c1, d[2], color[N], ok[N];
vector<int> S[N];

void DFS(int u, int d, int col) {
    c1 += col;
    color[u] = col;
    for(int v : S[u]) if (v != d)
        DFS(v, u, col ^ 1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        c1 = 0;
        for(int i=1; i<=n; ++i) S[i].clear();
        cin >> n;
        for(int i=1; i<n; ++i) {
            int u, v;
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        DFS(1, 1, 0);

        if (c1 > n/2) {
            c1 = n - c1;
            for(int i=1; i<=n; ++i) color[i] ^= 1;
        }
        for(int i=1; i<=n; ++i) ok[i] = 0;
        for(int i=0; i<18; ++i) if ((c1>>i)&1) {
            for(int j=0; j<(1<<i); ++j) ok[(1<<i) + j] = 1;
        }
        d[0] = d[1] = 1;
        for(int i=1; i<=n; ++i) {
            int v = color[i];
            while (ok[d[v]] != v) ++d[v];
            cout << d[v]++ << ' ';
        }
        cout << '\n';
    }
}