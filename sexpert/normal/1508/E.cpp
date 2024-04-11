#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
int tin[MAXN], tin2[MAXN], tout[MAXN], opos[MAXN], par[MAXN], lab[MAXN], dep[MAXN], pos[MAXN], curt, outt;
vector<int> adj[MAXN];

void dfs(int s) {
    curt++;
    tin[s] = curt;
    dep[s] = (s > 1 ? dep[par[s]] + 1 : 0);
    for(auto &v : adj[s])
        dfs(v);
    tout[s] = curt;
    outt++;
    opos[s] = outt;
}

void dfs2(int s, int lb) {
    curt++;
    tin2[s] = curt;
    for(auto &v : adj[s])
        if(lab[v] >= lb)
            dfs2(v, lb);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> lab[i];
        pos[lab[i]] = i;
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        par[v] = u;
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), [&](int u, int v){ return lab[u] < lab[v]; });

    dfs(1);

    int sta = lab[1] - 1;

    ll ops = 0;
    bool good = true;
    for(int u = 1; u <= sta; u++)
        ops += dep[pos[u]];

    int tar = 0;
    for(int i = 1; i <= n; i++)
        if(opos[i] == sta)
            tar = i;

    int u = pos[sta];
    if(tout[u] < tin[tar] || tin[u] > tin[tar])
        good = false;

    while(dep[u] != 0) {
        swap(pos[lab[u]], pos[lab[par[u]]]);
        swap(lab[u], lab[par[u]]);
        u = par[u];
    }

    for(int i = 1; i < sta; i++)
        if(opos[pos[i]] != i)
            good = false;

    curt = 0;
    dfs2(1, sta);

    int df = (sta ? sta - 1 : 0);
    for(int i = max(sta, 1); i <= n; i++)
        if(lab[pos[i]] != tin2[pos[i]] + df)
            good = false;

    if(!good) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << ops << '\n';
    for(int i = 1; i <= n; i++)
        cout << tin[i] << " ";
    cout << '\n';
}