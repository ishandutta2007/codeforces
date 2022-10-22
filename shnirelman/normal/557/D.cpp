#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
//const int M = 1e5 + 13;
const int A = 213;

/*
1
5
1 2 1 2 3
*/

vector<int> g[N];
bool used[N];
int col[N];
int cnt[2];

bool dfs1(int v, int cl) {
    col[v] = cl;
    used[v] = true;
    cnt[cl]++;

    cl ^= 1;

    for(auto u : g[v]) {
        if(used[u]) {
            if(col[u] != cl)
                return true;
        } else {
            if(dfs1(u, cl))
                return true;
        }
    }

    return false;
}


signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    if(m == 0) {
        li ans = n * 1ll * (n - 1) * (n - 2) / 6;
        cout << 3 << ' ' << ans << endl;
        return 0;
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            cnt[0] = cnt[1] = 0;
            if(dfs1(i, 0)) {
                cout << 0 << ' ' << 1 << endl;
                return 0;
            }

            ans += cnt[0] * 1ll * (cnt[0] - 1) / 2;
            ans += cnt[1] * 1ll * (cnt[1] - 1) / 2;
        }
    }

    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, int(g[i].size()));
    }

    if(mx == 1) {
        cout << 2 << ' ' << m * 1ll * (n - 2) << endl;
        return 0;
    }

    cout << 1 << ' ' << ans << endl;
}