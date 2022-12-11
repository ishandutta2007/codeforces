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

typedef int_fast64_t ll;
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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    start();

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        a[i] = input<ll>();
        b[i] = input<ll>();
    }
    ll res = a[0] * b[0];
    for (int i = 1; i < n; ++i) {
        res = gcd(res, a[i] * b[i]);
    }
    for (int i = 0; i < n; ++i) {
        res = max(gcd(res, a[i]), gcd(res, b[i]));
    }
    if (res == 1) {
        cout << -1;
        return 0;
    }
    cout << res;
    return 0;
}