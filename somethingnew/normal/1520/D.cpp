#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n * 3 + 2);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a[t - i + n]++;
    }
    ll res = 0;
    for (auto i : a) {
        res += (i) * (i - 1) / 2;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}