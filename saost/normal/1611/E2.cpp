#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 200005;
int t, n, k, x, a[N], b[N], exist[N];
vector<int> S[N];
queue<int> Q;

bool DFS(int u, int d, int h = 0) {
    if (h >= a[u]) {
        exist[b[u]] = 1;
        return false;
    }
    if (u != 1 && S[u].size() == 1) return true;
    for(int v : S[u]) if (v != d) {
        if (DFS(v, u, h + 1)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for(int i=1; i<=n; ++i) a[i] = 0x3c3c3c3c, b[i] = exist[i] = 0, S[i].clear();
        for(int i=1; i<=k; ++i) cin >> x, Q.push(x), a[x] = 0, b[x] = x;
        for(int i=2; i<=n; ++i) {
            int u, v;
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : S[u]) if (a[v] == 0x3c3c3c3c) {
                a[v] = a[u] + 1;
                b[v] = b[u];
                Q.push(v);
            }
        }
        if (DFS(1, 1)) cout << -1 << '\n';
        else {
            int res = 0;
            for(int i=1; i<=n; ++i) res += exist[i];
            cout << res << '\n';
        }
    }
}