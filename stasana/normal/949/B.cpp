#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;

ll get(ll x, ll n) {
    while (x % 2 == 0) {
        x += (n - x / 2);
    }
    return (x + 1) / 2;
}

int main() {
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        cout << get(x, n) << endl;
    }
    return 0;
}