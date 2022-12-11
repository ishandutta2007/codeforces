// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll is_rev = 0;
    ll flag = 0;
    ll left = 0;
    ll right = n - 1;
    vector<ll> res;
    for (ll i = n - 1; i >= 0; --i) {
        ll x;
        if (flag) {
            x = a[right] - '0';
            --right;
        } else {
            x = a[left] - '0';
            ++left;
        }
        ll need = b[i] - '0';
        if ((x ^ is_rev) == need) {
            res.emplace_back(1);
        }
        res.emplace_back(i + 1);
        is_rev ^= 1;
        flag = 1 - flag;
    }
    cout << res.size() << " ";
    for (ll i : res) {
        cout << i << " ";
    }
    cout << "\n";
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