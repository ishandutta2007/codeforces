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

    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        ll fa, ta, fb, tb;
        cin >> ta >> fa >> tb >> fb;
        ll res = 0;

        if (ta != tb) {
            if (fa > b || fa < a) {
                res += min(abs(b - fa), abs(a - fa));
                if (fa > b) {
                    fa = b;
                }
                else {
                    fa = a;
                }
            }
            res += abs(ta - tb);
            ta = tb;
        }
        res += abs(fa - fb);
        cout << res << "\n";
    }

    return 0;
}