#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(ll n, ll x, ll y) {
    ll res = 0;

    if ((x + y) % 2 == 1) {
        res = ((n * n - 1) / 2 + 1);
    }
    res += (n * (x - 1) + y + 1) / 2;
    cout << res << "\n";
}

int main() {
    start();

    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        ll x = input<ll>();
        ll y = input<ll>();
        solve(n, x, y);
    }

    return 0;
}