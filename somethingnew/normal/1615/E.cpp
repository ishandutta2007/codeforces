#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
#define int long long
void perelivka(multiset<int> &a, multiset<int> &b) {
    if (a.size() < b.size())
        swap(a, b);
    for (auto i : b) {
        a.insert(i);
    }
    b.clear();
}
vector<vector<int>> g;
multiset<int> dfs(int v, int p) {
    multiset<int> a = {0};
    for (auto i : g[v]) {
        if (i != p) {
            multiset<int> b = dfs(i, v);
            perelivka(a, b);
        }
    }
    int x = *--a.end();
    a.erase(--a.end());
    a.insert(x + 1);
    return a;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    g.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto a = dfs(0, -1);
    int n2 = n, t = 0;
    while (n2 != 0 and t < k) {
        n2 -= *--a.end();
        a.erase(--a.end());
        t++;
    }
    if (n2 == 0) {
        long long res = max(t, min(k, n / 2));
        cout << res * (n - res);
    } else {
        if (k - n2 < 0) {
            int res = 0;
            for (int i = 0; i <= n2; ++i) {
                res = min(res, (0ll + n - i - k) * (0ll + k - i));
            }
            cout << res;
            return 0;
        }
        cout << (0ll + n - n2 - k) * (0ll + k - n2);
    }
}