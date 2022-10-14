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
    vector<int> X(n);
    for (int i = 0; i < n; i++) cin >> X[i];
    sort(X.begin(), X.end());
    int ans = 0;
    vector<int> Y;
    set<int> used;
    for (auto e : X) used.insert(e);
    for (int len = 1; len < 1e7; len++) {
        vector<int> x2;
        for (int i = 0; i < n; i++) {
            bool f = false;
            if (Y.size() < m && used.find(X[i] - len) == used.end()) {
                ans += len;
                used.insert(X[i] - len);
                Y.pb(X[i] - len);
                f = true;
            }
            if (Y.size() < m && used.find(X[i] + len) == used.end()) {
                ans += len;
                used.insert(X[i] + len);
                Y.pb(X[i] + len);
                f = true;
            }
            if (f) {
                x2.pb(X[i]);
            }
        }
        X = x2;
        n = x2.size();
        if (Y.size() == m) {
            break;
        }
    }
    cout << ans << '\n';
    for (auto x : Y) {
        cout << x << ' ';
    }


}