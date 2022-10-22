#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 2e6 + 9;
const int LOGN = 20;

vector<int> g[N];
int a[N];
int used[N];
int d[N];

int dfs(int v, int x) {
    used[v] = 1;
    d[v] = 1;

    for(int u : g[v]) if(a[u] <= x) {
        if(used[u] == 0)
            d[v] = max(d[v], 1 + dfs(u, x));
        else if(used[u] == 1)
            return d[v] = INF;
        else
            d[v] = max(d[v], d[u] + 1);
    }

    used[v] = 2;
    return d[v];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    li k;
    cin >> n >> m >> k;

    k = min(k, INF * 1ll);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
    }

    vector<int> b(a, a + n);
    sort(b.begin(), b.end());

    int l = -1, r = n;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int res = 0;
        for(int i = 0; i < n; i++) {
            used[i] = false;
            d[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            if(!used[i] && a[i] <= b[m])
                res = max(res, dfs(i, b[m]));
        }

        if(res >= k)
            r = m;
        else
            l = m;
    }

    cout << (r == n ? -1 : b[r])  << endl;

//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();
}