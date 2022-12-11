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

void solve() {
    ll n;
    cin >> n;
    set<ll> result;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) {
            continue;
        }
        result.insert(n / i + (n / i) * (n - i) / 2);
        result.insert(n / (n / i) + (n / (n / i)) * (n - (n / i)) / 2);
    }
    for (ll i : result) {
        cout << i << " ";
    }
}

int main() {
    start();
    solve();
    return 0;
}