#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define int long long
#define ll long long

const int N = 2e5 + 7;

int n, a[N], b[N];
vector<int> g[N];
int h[N];
bool us[N];

void dfs(int v) {
    for (auto u : g[v]) {
        h[u] = h[v] + 1;
        dfs(u);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            b[i]--;
            g[b[i]].pb(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) dfs(i);
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) st.insert({h[i], i});
    }
    int ans = 0;
    vector<int> ord;
    while (!st.empty()) {
        auto it = prev(st.end());
        int v = it->y;
        st.erase(it);
        ans += a[v];
        us[v] = 1;
        ord.pb(v);
        if (b[v] != -1) {
            a[b[v]] += a[v];
            if (a[b[v]] >= 0) st.insert({h[b[v]], b[v]});
        }
    }
    vector<pair<int, int>> vs;
    for (int i = 0; i < n; i++) {
        if (!us[i]) vs.pb({h[i], i});
    }
    sort(all(vs));
    for (auto el : vs) {
        ans += a[el.y];
        ord.pb(el.y);
    }
    cout << ans << '\n';
    for (auto v : ord) cout << v + 1 << " ";
    return 0;
}