#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()
vector<vector<int>> g;
vector<int> h;
vector<int> cnt;
int dfs(int v, int p) {
    int cv = v;
    for (auto i : g[v]) {
        if (i != p) {
            int q = dfs(i, v);
            if (cnt[q] > cnt[cv])
                cv = q;
        }
    }
    cnt[cv] = max(cnt[cv], h[v]);
    return cv;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cnt.assign(n, {});
    g.assign(n, {});
    h.assign(n, {});
    int v = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > h[v])
            v = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ad = {h[v]};
    for (auto i : g[v]) {
        ad.push_back(h[v] - cnt[dfs(i, v)]);
    }
    sort(all(ad));
    long long res = ad[0] + ad[1];
    for (auto i : cnt)
        res += i;
    cout << res << '\n';
}