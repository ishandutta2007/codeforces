#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, n, k, l1, r1, l2, r2, d1, ml, mr, d2;
    cin >> t;
    rep(z, t) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        ml = max(l1, l2);
        mr = min(r1, r2);
        if (ml < mr) {
            k = max(k - (mr - ml) * n, 0ll);
            d1 = 0;
            d2 = r1 - l1 + r2 - l2 - 2 * (mr - ml);
        }
        else {
            d1 = ml - mr;
            d2 = max(r1, r2) - min(l1, l2);
        }
        ll ans = (k == 0 ? 0 : 1e18);
        for (int i = 1; i <= n; i++)
            ans = min(ans, d1 * i + k * 2 - min(d2 * i, k));
        cout << ans << '\n';
    }
}