#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <cstring>
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second

using ll = long long;
using vi = vector<int>;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

ll solve(ll x) {
    vi v;
    while (x > 0) {
        v.pb(x % 10);
        x /= 10;
    }
    reverse(all(v));
    int sum = 9 * (sz(v) - 1);
    ll ans = 0;
    for (int i = 0; i < sz(v) - 1; ++i) {
        ans = ans * 10 + 9;
    }
    ll cur = 0;
    int cur_sum = 0;
    for (int i = 0; i < sz(v); ++i) {
        for (int j = (i == 0); j < v[i]; ++j) {
            ll res = cur * 10 + j;
            int res_sum = cur_sum + j;
            for (int z = i + 1; z < sz(v); ++z) {
                res = res * 10 + 9;
                res_sum += 9;
            }
            if (res_sum > sum || (res_sum == sum && res > ans)) {
                sum = res_sum;
                ans = res;
            }
        }
        cur = cur * 10 + v[i];
        cur_sum += v[i];
    }
    if (cur_sum > sum || (cur_sum == sum && cur > ans)) {
        sum = cur_sum;
        ans = cur;
    }
    return ans;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}