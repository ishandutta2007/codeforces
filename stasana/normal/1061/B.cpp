// Megumin top

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll res  = 0;
    ll cnt  = 1;
    ll need = 1;
    for (ll i = 0; i < n - 1; ++i) {
        ++res;
        if (a[i] >= need) {
            ++need;
        }
    }
    cout << sum - (res + max(a.back() - need + 1, 1LL));
    return 0;
}