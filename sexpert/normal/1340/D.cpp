#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int n, mx;
vector<ii> ans;

void dfs(int s, int ent, int p = 0) {
    int cur = ent;
    ans.push_back({s, cur});
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(cur == mx - 1) {
            cur = mx - 1 - (int)(adj[s].size());
            ans.push_back({s, cur});
        }
        dfs(v, ++cur, s);
        ans.push_back({s, cur});
    }
    if((cur + mx)%mx != (ent - 1 + mx)%mx && s != 1)
        ans.push_back({s, ent - 1});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        mx = max(mx, (int)adj[i].size() + 1);
    dfs(1, 0);
    cout << ans.size() << '\n';
    for(auto p : ans)
        cout << p.first << " " << (p.second + mx) % mx << '\n';
}