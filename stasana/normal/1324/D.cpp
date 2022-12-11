// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] -= x;
    }
    sort(a.begin(), a.end());
    ll result = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] <= 0) {
            result += a.end() - upper_bound(a.begin(), a.end(), -a[i]);
        } else {
            result += n - i - 1;
        }
    }
    cout << result << endl;
    return 0;   
}