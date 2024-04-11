// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

string s;

ll f(ll left, ll right, char ch) {
    if (right - left == 1) {
        return s[left] != ch;
    }
    ll mid = (left + right) / 2;
    ll cnt_1 = 0;
    ll cnt_2 = 0;
    for (ll i = left; i < mid; ++i) {
        if (s[i] != ch) {
            ++cnt_1;
        }
    }
    for (ll i = mid; i < right; ++i) {
        if (s[i] != ch) {
            ++cnt_2;
        }
    }
    return min(cnt_1 + f(mid, right, ch + 1), cnt_2 + f(left, mid, ch + 1));
}

void solve() {
    ll n;
    cin >> n;
    cin >> s;
    cout << f(0, n, 'a') << endl;
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