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



int main() {
    start();

    ll n, m;
    cin >> n >> m;
    ll res = 0;
    ll resx = 0;
    for (ll i = 0; i < m; ++i) {
        ll x, d;
        cin >> x >> d;
        resx += x;
        if (d > 0) {
            res += (n - 1) * d * n / 2;
        }
        else {
            if (n % 2 == 0) {
                res += ((n / 2) - 1) * d * (n / 2) + (n / 2) * d;
            }
            else {
                ll N = (n - 1) / 2 + 1;
                res += (N - 1) * d * N;
            }
        }
    }
    cout << fixed << setprecision(12) << (ld(res) / n) + resx;
    //system("pause");
    return 0;
}