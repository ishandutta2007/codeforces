#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, k;
vector<int> g[111111];
int pr[111111], h[111111];
int us[111111];

void dfs(int v) {
    us[v] = 1;
    for (auto u : g[v]) {
        if (u == pr[v]) continue;
        if (us[u] == 1) {
            if (h[v] - h[u] + 1 <= k) {
                vector<int> ans;
                int w = v;
                while (w != u) {
                    ans.pb(w);
                    w = pr[w];
                }
                ans.pb(u);
                cout << 2 << '\n' << ans.size() << '\n';
                for (auto x : ans) cout << x+1 << " ";
                exit(0);
            }
        } else {
            if (!us[u]) {
                pr[u] = v;
                h[u] = h[v]+1;
                dfs(u);
            }
        }
    }
    us[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    pr[0] = -1;
    dfs(0);
    vector<pair<int, int>> vs;
    for (int i = 0; i < n; i++) vs.pb({h[i], i});
    sort(all(vs));
    reverse(all(vs));
    memset(us, 0, sizeof(us));
    vector<int> ans;
    for (auto e : vs) {
        int v = e.y;
        if (ans.size() == (k+1)/2) break;
        if (!us[v]) {
            ans.pb(v);
            us[v] = 1;
            for (auto u : g[v]) us[u] = 1;
        }
    }
    cout << 1 << '\n';
    for (auto v : ans) cout << v+1 << " ";
    return 0;
}