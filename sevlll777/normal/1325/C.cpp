#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n==2){
        cout<<"0";
        return 0;
    }
    vector<vector<pair<int, int>>> gr(n);
    map<pair<int, int>, int> reb;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].pb({b, i});
        gr[b].pb({a, i});
        reb[{a, b}] = i;
        reb[{b, a}] = i;
    }
    int cnt = 0;
    vector<int> ans(n - 1, -1);
    vector<int> sos;
    for (int v = 0; v < n; v++) {
        if (gr[v].size() == 1) {
            sos.pb(v);
            ans[reb[{v, gr[v][0].first}]] = cnt++;
            if (cnt == 2) {
                break;
            }
        }
    }
    int sd = sos[0], fd = sos[1];
    vector<bool> used(n, false);
    used[sd] = true;
    deque<int> q = {sd};
    vector<int> par(n, -1);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : gr[v]) {
            if (!used[u.first]) {
                used[u.first] = true;
                q.pb(u.first);
                par[u.first] = v;
                if (u.first == fd) {
                    break;
                }

            }
        }
    }
    int yy = n - 2;
    fd = par[fd];
    while (par[fd] != sd) {
        ans[reb[{fd, par[fd]}]] = yy--;
        fd = par[fd];
    }
    for (int y = 0; y < n - 1; y++) {
        if (ans[y] == -1) {
            cout << cnt++ << ' ';
        } else {
            cout << ans[y] << ' ';
        }
    }
}