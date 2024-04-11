#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

ll y;

long double ga(ll x) {
    ll n = x / (2 * y);
    if (n == 0)
        return 1e12;
    return (x + 0.0) / (n * 2.0);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    ll x;
    cin >> x >> y;

    if (y > x) {
        cout << "-1\n";
        return 0;
    }

    if (x == y) {
        cout << x;
        return 0;
    }

    cout.precision(10);
    cout << fixed << min(ga(x + y), ga(x - y));

    return 0;
}