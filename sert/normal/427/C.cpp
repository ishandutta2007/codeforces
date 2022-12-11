#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
const ll md = 1e9 + 7;

vector <int> es[N], o[N];
bool u[N], ua[N];
ll mn, kol;
ll ans, kola = 1;
int c[N];
vector <int> w;

void dfo(int v) {
    if (ua[v]) return;
    ua[v] = true;
    if (c[v] == mn)
        kol++;
    if (c[v] < mn) {
        mn = c[v];
        kol = 1;
    }
    for (int i = 0; i < o[v].size(); i++)
        dfo(o[v][i]);
}

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;

    for (int i = 0; i < es[v].size(); i++)
        dfs(es[v][i]);

    w.push_back(v);
}
int n, m, v1, v2;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", c + i);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        es[v1 - 1].push_back(v2 - 1);
        o[v2 - 1].push_back(v1 - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!u[i])
            dfs(i);
    }

    for (int i = w.size() - 1; i >= 0; i--) {
        if (ua[w[i]]) continue;
        mn = 2e9;
        kol = 1;
        dfo(w[i]);
        ans += mn;
        kola = (kola * kol) % md;
    }

    cout << ans << " " << kola;

    return 0;
}