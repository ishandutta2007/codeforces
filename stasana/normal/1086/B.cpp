// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n, s;
    cin >> n >> s;
    s <<= 1;
    vector<ll> cnt(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        ++cnt[u];
        ++cnt[v];
    }
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        if (cnt[i] == 1) {
            ++res;
        }
    }
    cout << fixed << setprecision(24) << (long double)s / (long double)res << endl;
    return 0;
}