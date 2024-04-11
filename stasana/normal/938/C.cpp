#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;

void solve(ll x) {
    for (ll m = 1; m < 1e4; ++m) {
        ll left = m;
        ll right = 1e9;
        while (right - left > 1) {
            ll mid = (right - left) / 2 + left;
            if (mid * mid - (mid * mid) / (m * m) > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (left * left - (left  / m) * (left  / m) == x) {
            cout << left << " " << m << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        ll x;
        cin >> x;
        solve(x);
    }
    return 0;
}