#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150000 + 5;
vector<int> comp[MAXN];
int par[MAXN], sz[MAXN];

int find(int u) {
    return (par[u] == -1 ? u : par[u] = find(par[u]));
}

void join(int u, int v) {
    par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(par, -1, sizeof par);
    for(int i = 0; i < MAXN; i++)
        sz[i] = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        comp[i] = {i};
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u = find(u), v = find(v);
        if(sz[v] > sz[u])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        int pt = comp[u].size();
        //comp[u].resize(comp[u].size() + comp[v].size());
        comp[u].insert(comp[u].end(), comp[v].begin(), comp[v].end());
        comp[v].clear();
        comp[v].shrink_to_fit();
        /*while(!comp[v].empty()) {
            int x = comp[v].back();
            comp[v].pop_back();
            comp[u][pt++] = x;
        }*/
    }
    int c = find(1);
    for(auto x : comp[c])
        cout << x << " ";
    cout << endl;
}