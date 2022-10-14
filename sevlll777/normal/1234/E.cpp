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
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define fir first
#define sec second
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
using namespace std;
int a, b, n, m, t, k, x, r, l, q, i, j;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int> X;
    for (int i = 0; i < m; i++) {
        cin >> b;
        X.pb(b);
    }
    vector<vector<int>> neigh(n + 1);
    neigh[X[0]].pb(X[1]);
    neigh[X[m - 1]].pb(X[m - 2]);
    for (int i2 = 1; i2 < m - 1; i2++) {
        neigh[X[i2]].pb(X[i2 - 1]);
        neigh[X[i2]].pb(X[i2 + 1]);
    }
    vector<tupint > E;
    vector<int> ans(n + 1);
    for (int i3 = 1; i3 <= n; i3++) {
        for (auto j3 : neigh[i3]) {
            if (i3 != j3) {
                i = min(i3, j3);
                j = max(i3, j3);
                E.pb({1, -1, j - i});
                E.pb({i, 1, j - i});
                ans[i] += j - 1;
                E.pb({i + 1, -1, j - i - 1});
                E.pb({j, 1, j - i - 1});
                ans[j] += i;
                E.pb({j + 1, -1, j - i});
                E.pb({n + 1, 1, j - i});
            }
        }
    }
    sort(E.begin(), E.end());
    int lx = 1;
    int b = 0;
    for (auto tp : E) {
        int x = get<0>(tp);
        int t = get<1>(tp);
        int s = get<2>(tp);
        if (lx < x) {
            for (int i = lx; i < x; i++) {
                ans[i] += b;
            }
        }
        if (t == -1) {
            b += s;
        } else {
            b -= s;
        }
        lx = x;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] / 2 << ' ';
    }
    return 0;
}