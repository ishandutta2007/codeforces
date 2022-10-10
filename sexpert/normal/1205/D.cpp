#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1010;
vector<int> adj[MAXN];
int sz[MAXN], n, cen, cur, step, tot, big;

void get_sz(int s, int p = 0) {
    sz[s] = 1;
    for(auto v : adj[s]) {
        if(v != p) {
            get_sz(v, s);
            sz[s] += sz[v];
        }
    }
}

int get_cen(int s, int p = 0) {
    for(auto v : adj[s]) {
        if(v == p) continue;
        if(sz[v] > sz[1]/2)
            return get_cen(v, s);
    }
    return s;
}

void dfs(int s, int path, int p) {
    for(int i = 0; i < adj[s].size(); i++) {
        if(s == cen && i <= big && step > 1) continue;
        int v = adj[s][i];
        if(v == p) continue;
        cout << s << " " << v << " " << (cur += step) - path << '\n';
        dfs(v, cur, s);
        if(cur == tot)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_sz(1);
    cen = get_cen(1);
    get_sz(cen);
    sort(adj[cen].rbegin(), adj[cen].rend(), [&](int i, int j){ return sz[i] < sz[j]; });
    for(int i = 0; i < adj[cen].size(); i++) {
        tot += sz[adj[cen][i]];
        if(tot >= n/3) {
            big = i;
            break;
        }
    }
    step = 1;
    cur = 0;
    dfs(cen, 0, 0);
    step = tot + 1;
    cur = 0;
    dfs(cen, 0, 0);
}