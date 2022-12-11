// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef int64_t ll;

void solve() {
    string s;
    cin >> s;
    ll n = (ll)s.size();
    s = "R" + s + "R";
    ll cnt = 0;
    ll mx = 0;
    for (ll i = n + 1; i >= 0; --i) {
        if (s[i] == 'R') {
            mx = max(cnt + 1, mx);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    cout << mx << endl;
}

int main() {
    ll n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}