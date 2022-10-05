#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
vector<vector<int>> g;
vector<int> seen;
int cntik;
void dfs(int v) {
    if (seen[v])
        return;
    seen[v] = 1;
    cntik++;
    for (auto i : g[v])
        dfs(i);
}
int solve(int m) {
    int n = g.size();
    seen.assign(n, 0);
    vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == 0) {
            cntik = 0;
            dfs(i);
            cnt.push_back(cntik);
        }
    }
    int t = m + 1 - (n - cnt.size());
    sort(all(cnt));
    int res = 0;
    for (int i = max(0ull, + cnt.size() - t); i < cnt.size(); ++i) {
        res += cnt[i];
    }
    return res - 1;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    g.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;a--;b--;
        g[a].push_back(b);g[b].push_back(a);
        cout << solve(i + 1) << '\n';
    }
}