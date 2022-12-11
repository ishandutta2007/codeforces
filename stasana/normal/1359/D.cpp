// Bipolar disorder is very cool
     
#include <algorithm>
#include <iostream>
#include <vector>

typedef int64_t ll;
     
using namespace std;

ll n;
vector<ll> a;

ll f(ll left, ll right) {
    if (left + 1 == right) {
        return 0;
    }
    ll mid = (left + right) >> 1;
    ll result = max(f(left, mid), f(mid, right));
    ll mx = -100;
    ll sum = 0;
    vector<ll> left_segment(61, -1'000'000'000);
    vector<ll> right_segment(61, -1'000'000'000);
    for (ll i = mid; i < right; ++i) {
        sum += a[i];
        mx = max(mx, a[i]);
        right_segment[mx + 30] = max(right_segment[mx + 30], sum);
    }
    sum = 0;
    mx = -100;
    for (ll i = mid - 1; i >= left; --i) {
        sum += a[i];
        mx = max(mx, a[i]);
        left_segment[mx + 30] = max(left_segment[mx + 30], sum);
    }
    left_segment[30] = 0;
    right_segment[30] = 0;
    for (ll i = 0; i < 61; ++i) {
        for (ll j = 0; j < 61; ++j) {
            if (left_segment[i] == -1'000'000'000) {
                continue;
            }
            if (right_segment[j] == -1'000'000'000) {
                continue;
            }
            result = max(result, left_segment[i] + right_segment[j] - max(i, j) + 30);
        }
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    a.resize(n);
    for (ll& i : a) {
        cin >> i;
    }
    cout << f(0, n) << endl;
    return 0;
}