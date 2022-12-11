#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }
    for (ll i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    a.insert(a.begin(), (ll)0);
    ll result = 0;
    set<ll> kek;
    ll left = 0;
    for (ll i = 0; i <= n; ++i) {
        if (kek.find(a[i]) != kek.end()) {
            while (a[left] != a[i]) {
                kek.erase(a[left]);
                ++left;
            }
            kek.erase(a[left]);
            ++left;
        }
        kek.insert(a[i]);
        result += i - left;
    }
    cout << result << endl;
}

int main() {
    start();
    solve();
    return 0;
}