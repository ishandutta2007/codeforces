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

using namespace std;
int mod = 998244353;
long long slv2(vector<pair<int, int>> &a, int m) {
    vector<int> prefsum(m + 1);
    vector<int> ares(m + 1);
    ares[0] = 1;
    for (auto [l, r] : a) {
        prefsum[0] = ares[0];
        for (int i = 1; i <= m; ++i) {
            prefsum[i] = ares[i] + prefsum[i - 1];
            if (prefsum[i] >= mod)
                prefsum[i] -= mod;
        }
        for (int i = 0; i <= m; ++i) {
            ares[i] = (i - l >= 0 ? (prefsum[i - l] - (i - r > 0 ? prefsum[i-r-1] : 0)) : 0) % mod;
        }
    }
    long long sm = 0;
    for (auto i : ares)
        sm += i;
    sm %= mod;
    return sm;
}
long long cnt(vector<pair<int, int>> a, int m, int gc) {
    m /= gc;
    for (int i = 0; i < a.size(); ++i) {
        a[i].first = (a[i].first + gc - 1) / gc;
        a[i].second = a[i].second / gc;
    }
    return slv2(a, m);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (auto &i : a)
        cin >> i.first >> i.second;
    vector<int> resushki(m + 1, 1);
    long long res = cnt(a, m, 1);
    for (int i = 2; i <= m; ++i) {
        int k = resushki[i];
        if (k != 0) {
            res -= k * cnt(a, m, i);
            for (int j = i; j <= m; j += i) {
                resushki[j] -= k;
            }
        }
    }
    res %= mod;
    res += mod;
    res %= mod;
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int n = 1;
    while (n--) solve();
}