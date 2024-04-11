#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(a) (a).begin(), (a).end()
#define int long long
using namespace std;
vector<int> seen;
vector<vector<int>> g;
void dfs(int v) {
    if (seen[v])
        return;
    seen[v] = 1;
    for (auto i : g[v])
        dfs(i);
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(all(a));
    sort(all(b));
    seen.assign(n, 0);
    g.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        g[a[i].second].push_back(a[i + 1].second);
        g[b[i].second].push_back(b[i + 1].second);
    }
    dfs(a.back().second);
    dfs(b.back().second);
    for (auto i : seen)
        cout << i;
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}