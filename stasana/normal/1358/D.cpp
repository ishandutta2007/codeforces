// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

typedef int64_t ll;

using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }
    for (ll i = 0; i < n; ++i) {
        a.emplace_back(a[i]);
    }
    n = 2 * n;
    ll ptr = 0;
    ll result = 0;
    ll sum = 0;
    ll local_result = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
        local_result += a[i] * (a[i] + 1) / 2;
        while (sum - a[ptr] > x) {
            sum -= a[ptr];
            local_result -= a[ptr] * (a[ptr] + 1) / 2;
            ++ptr;
        }
        ll left = -1;
        ll right = a[ptr];
        while (right - left > 1) {
            ll mid = left + right >> 1;
            if (sum - mid <= x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        result = max(result, local_result - right * (right + 1) / 2);
    }
    cout << result << endl;
    return 0;
}