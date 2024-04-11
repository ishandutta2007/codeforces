// Yunyun loli

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<ll> y;
    for (int i = 0; i < m; ++i) {
        ll x1, x2, yy;
        cin >> x1 >> x2 >> yy;
        if (x1 != 1) {
            continue;
        }
        y.emplace_back(x2);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.emplace_back(1e9);
    ll res = 1e9;
    for (int i = 0; i <= n; ++i) {
        ll left = -1;
        ll right = y.size();
        while (right - left > 1) {
            ll mid = (right + left) / 2;
            if (x[i] > y[mid]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        res = min(res, i + y.size() - right);
    }
    cout << res;
    return 0;
}