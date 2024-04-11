#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "set"
#include "array"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int mod = 998244353;
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
vector<int> delit(int x) {
    vector<int> del;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            del.push_back(i);
            x /= i;
        }
    }
    if (x != 1)
        del.push_back(x);
    return del;
}
vector<vector<array<int, 3>>> g;
int ansval = 0;
void dfs1(int v, int p, vector<int> &n1, vector<int> &mxn) {
    for (auto [i, x, y] : g[v]) {
        if (i == p)
            continue;
        vector<int> dx = delit(x), dy = delit(y);
        for (auto i : dy)
            n1[i]--;
        for (auto i : dx) {
            n1[i]++;
            mxn[i] = max(n1[i], mxn[i]);
        }
        dfs1(i, v, n1, mxn);
        for (auto i : dy)
            n1[i]++;
        for (auto i : dx) {
            n1[i]--;
        }
    }
}
int inv(int x) {
    return pw(x, mod - 2);
}
void dfs2(int v, int p, int val) {
    ansval += val;
    for (auto [i, x, y] : g[v]) {
        if (p == i)
            continue;
        dfs2(i, v, val * inv(x) % mod * y % mod);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n + 1), mxnums(n + 1);
    g.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--;b--;
        g[a].push_back({b, x, y});
        g[b].push_back({a, y, x});
    }
    dfs1(0, -1, nums, mxnums);
    ansval = 0;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (mxnums[i])
            res = res * pw(i, mxnums[i]) % mod;
    }
    dfs2(0, -1, res);
    ansval %= mod;
    cout << ansval << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}