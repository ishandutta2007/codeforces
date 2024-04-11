#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 34;

bool u[N], uf[N], fnd;
int d[N], n, m, v1, v2, fn;
vector <int> es[N];
bool ok = true;

void dfs(int v, int pr) {
    if (uf[v]) return;
    u[v] = true;
    for (int i = 0; i < es[v].size() && !fnd; i++) {
        if (es[v][i] == pr) continue;
        if (u[es[v][i]]) {
            fnd = true;
            fn = es[v][i];
        } else if (!uf[es[v][i]])
            dfs(es[v][i], v);
    }
    u[v] = ok && fnd;
    if (v == fn && fnd) 
        ok = false;
    uf[v] = true;
}

void dfs_d(int v, int ds) {
    d[v] = ds;
    u[v] = true;
    for (int i = 0; i < es[v].size(); i++)
        if (!u[es[v][i]])
            dfs_d(es[v][i], ds + 1);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    dfs(0, -34);
    for (int i = 0; i < n; i++) 
        uf[i] = u[i];
    for (int i = 0; i < n; i++)
        if (uf[i]) {
            dfs_d(i, 0);
        }
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
}