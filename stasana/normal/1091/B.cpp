// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

vector<ll> z_function(string s) {
    vector<ll> z(s.length());
    ll left = 0, right = 0;
    for (ll i = 1; i < s.length(); ++i) {
        if (i < right) {
            z[i] = min(right - i, z[i - left]);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (right < i + z[i]) {
            right = i + z[i];
            left = i;
        }
    }
    z[0] = s.length();
    return z;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    set<pair<ll, ll>> b;
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        b.insert(make_pair(x, y));
    }
    for (auto i : b) {
        ll f = 1;
        for (ll j = 0; j < n; ++j) {
            if (b.find(make_pair(a[0].first + i.first - a[j].first, a[0].second + i.second - a[j].second)) == b.end()) {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << a[0].first + i.first << " " << a[0].second + i.second << endl;
            return;
        }
    }
}

int main() {
    start();
    solve();
    return 0;
}