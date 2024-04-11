#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "unordered_map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> val(n), ans(n, 1);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        val[i] = k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            g[x].push_back(i);
        }
    }
    vector<int> seen(n);
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (val[i] == 0)
            que.push(i);
    }
    while (!que.empty()) {
        int v = que.front();
        seen[v] = 1;
        que.pop();
        for (auto i : g[v]) {
            val[i]--;
            if (i > v)
                ans[i] = max(ans[i], ans[v]);
            else
                ans[i] = max(ans[i], ans[v] + 1);
            if (val[i] == 0)
                que.push(i);
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == 0) {
            cout << "-1\n";
            return;
        }
        res = max(ans[i], res);
    }
    cout << res << '\n';
}
signed main() {
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}