#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
 
const int MAXN = 3e5 + 5;
int h[MAXN], cnt[MAXN][3], val[MAXN];
vector<ii> edges;
vector<int> adj[MAXN];
 
void dfs(int s, int p = 0) {
    h[s] = (p ? h[p] + 1 : 0);
    cnt[s][val[s]] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        for(int j = 0; j < 3; j++)
            cnt[s][j] += cnt[v][j];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for(auto e : edges) {
        int u = e.first, v = e.second;
        if(h[u] > h[v])
            swap(u, v);
        if((cnt[1][1] == cnt[v][1] && cnt[v][2] == 0) || (cnt[1][2] == cnt[v][2] && cnt[v][1] == 0)) {
            //cout << u << " " << v << endl;
            ans++;
        }
    }
    cout << ans << endl;
}