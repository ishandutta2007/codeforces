// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll result = 0;
    for (char bb = 'b'; bb < 'a' + 20; ++bb) {
        for (char aa = 'a'; aa < bb; ++aa) {
            bool flag = true;
            for (ll i = 0; i < n; ++i) {
                if (a[i] == aa && b[i] == bb) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            ++result;
            for (ll i = 0; i < n; ++i) {
                if (a[i] == b[i]) {
                    continue;
                }
                if (a[i] == aa) {
                    a[i] = bb;
                }
            }
        }
    }
    if (a == b) {
        cout << result << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }

    return 0;
}