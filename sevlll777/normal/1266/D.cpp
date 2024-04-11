#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> dolg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dolg[u] += w;
        dolg[v] -= w;
    }
    vector<int> neg; vector<int> pos;
    for (int v = 1; v <= n; v++) {
        if (dolg[v] < 0) {
            neg.pb(v);
            dolg[v] = -dolg[v];
        } else if (dolg[v] > 0) {
            pos.pb(v);
        }
    }
    vector<tupint> ans;
    while (!neg.empty() && !pos.empty()) {
        int v1 = neg.back();
        int v2 = pos.back();
        neg.pop_back();
        pos.pop_back();
        if (dolg[v1] > dolg[v2]) {
            ans.pb({v2, v1, dolg[v2]});
            dolg[v1] -= dolg[v2];
            dolg[v2] = 0;
            neg.pb(v1);
        } else if (dolg[v2] > dolg[v1]) {
            ans.pb({v2, v1, dolg[v1]});
            dolg[v2] -= dolg[v1];
            dolg[v1] = 0;
            pos.pb(v2);
        } else {
            ans.pb({v2, v1, dolg[v1]});
            dolg[v2] = 0;
            dolg[v1] = 0;
        }
    }
    cout << ans.size() << '\n';
    for (auto y : ans) {
        cout << get<0> (y) << ' ' << get<1> (y) << ' ' << get<2> (y) << '\n';
    }

}