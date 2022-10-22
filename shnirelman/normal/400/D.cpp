#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int K = 503;
const int INF = 1e9;

vector<int> g[N];
int d[K][K];
int c[K];
int a[N];
int used[N];
int T = 1;

int dfs(int v, int col) {
    used[v] = T;

    int res = (a[v] == col);

    for(auto u : g[v])
        if(used[u] < T)
            res += dfs(u, col);

    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int cur = 0;
    for(int i = 0; i < k; i++) {
        cin >> c[i];

        for(int j = 0; j < c[i]; j++)
            a[cur + j] = i;
        cur += c[i];
    }


    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            d[i][j] = (i == j ? 0 : INF);
        }
    }

    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        v--;
        u--;

        if(w == 0) {
            g[v].push_back(u);
            g[u].push_back(v);
        }

        if(a[v] == a[u]) {
            if(w == 0) {
                g[v].push_back(u);
                g[u].push_back(v);
            }
        } else {
            d[a[v]][a[u]] = min(d[a[v]][a[u]], w);
            d[a[u]][a[v]] = d[a[v]][a[u]];
        }
    }

    cur = 0;
    for(int i = 0; i < k; i++) {
        T++;
        if(dfs(cur, i) < c[i]) {
            cout << "No";
            return 0;
        }

        cur += c[i];
    }

    for(int l = 0; l < k; l++)
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);

    cout << "Yes" << endl;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++)
            cout << (d[i][j] < INF ? d[i][j] : -1) << ' ';
        cout << endl;
    }
}