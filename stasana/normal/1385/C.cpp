// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

bool check(vector<ll>& a) {
    ll old = -1;
    ll left = 0;
    ll right = (ll)a.size() - 1;
    while (right - left > 0) {
        ll x = min(a[left], a[right]);
        if (a[left] < a[right]) {
            ++left;
        } else {
            --right;
        }
        if (x < old) {
            return false;
        }
        old = x;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll left = -1;
    ll right = n;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        vector<ll> b;
        for (ll i = mid; i < n; ++i) {
            b.emplace_back(a[i]);
        }
        if (check(b)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }
    return 0;
}