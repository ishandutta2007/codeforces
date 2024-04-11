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
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = 0;
    for (ll i1 = 0; i1 <= a; ++i1) {
        if (i1 + 1 <= b && i1 + 2 <= c) {
            res = i1 + i1 + 1 + i1 + 2;
        }
    }
    cout << res;
}

int main() {
    start();
    solve();
    return 0;
}