#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
vector<vector<int>> g;
vector<int> val;
int res = 0;
int mod = ((int)1e9) + 7;
int gcd(int aa, int b) {
    if (aa == 0)
        return b;
    return gcd(b % aa, aa);
}
void dfs(int v, int p, vector<pair<int, int>> a) {
    for (int i = 0; i < a.size(); ++i) {
        a[i].first = gcd(a[i].first, val[v]);
    }
    a.push_back({val[v], 1});
    vector<pair<int, int>> b;
    for (int i = 0; i < a.size(); ++i) {
        if (b.empty())
            b.push_back(a[i]);
        else if (b.back().first == a[i].first)
            b.back().second += a[i].second;
        else
            b.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        res += b[i].first * b[i].second;
        res %= mod;
    }
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfs(i, v, b);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    g.assign(n, {});
    val.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    for (int j = 0; j < n - 1; ++j) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, {});
    cout << res;
}