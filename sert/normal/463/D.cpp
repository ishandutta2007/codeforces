#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e3 + 34;
const ld EPS = 1e-4;

int p[6][N];
vector <int> es[N];
int d[N];
int n, m, x;
bool u[N];
vector <int> so;
bool uq[N][N];

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;
    for (int i = 0; i < es[v].size(); i++)
        dfs(es[v][i]);
    so.push_back(v);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            p[i][x - 1] = j;
        }
    }
    bool fail;
    int ans = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        fail = false;
        for (int ii = 0; ii < m && !fail; ii++)
            if (p[ii][i] >= p[ii][j])
                fail = true;
        if (!fail) {
            //cerr << i << " " << j << "\n";
            es[i].push_back(j);
            uq[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs(i);
    reverse(so.begin(), so.end());

    for (int i = 0; i < n; i++) {
        x = so[i];
        d[x] = 1;
        for (int j = 0; j < i; j++)
            if (uq[so[j]][x])
                d[x] = max(d[x], 1 + d[so[j]]);
        ans = max(ans, d[x]);
    }
    cout << ans;

    return 0;
}