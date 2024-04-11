#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

vector<int> g[400100];
bool used[400100];

void dfs(int v) {
    used[v] = true;
    forn (i, g[v].size()) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    forn (i, q) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        y += n;
        g[x].pb(y);
        g[y].pb(x);
    }
    int ans = -1;
    forn (i, n + m) {
        if (!used[i]) {
            dfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}