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
    vector<pair<ll, ll>> a(3);
    vector<ll> x(3);
    vector<ll> y(3);
    for (ll i = 0; i < 3; ++i) {
        cin >> a[i].first >> a[i].second;
        x[i] = a[i].first;
        y[i] = a[i].second;
    }
    sort(a.begin(), a.end());
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<pair<ll, ll>> res;
    for (ll i = y[0]; i <= y[2]; ++i) {
        res.emplace_back(a[1].first, i);
    }
    for (ll i = a[0].first; i < a[1].first; ++i) {
        res.emplace_back(i, a[0].second);
    }
    for (ll i = a[1].first + 1; i <= a[2].first; ++i) {
        res.emplace_back(i, a[2].second);
    }
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}