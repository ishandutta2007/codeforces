#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    ll n, m, k;
    cin >> n >> m >> k;
    ll res = 0;
    for (ll i = 0; i < k; ++i) {
        res += max(n + n + m + m - 4, 1LL);
        n -= 4;
        m -= 4;
    }
    cout << res;
    return 0;
}