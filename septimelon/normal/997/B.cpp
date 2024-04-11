#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-7;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    ll ans = 0;
    for (ll cv = 0; cv < 9; ++cv) {
        for (ll cx = 0; cx < 9; ++cx) {
            bool broke = false;
            for (ll ncv = 0; ncv < 9; ++ncv) {
                for (ll ncx = 0; ncx < cx; ++ncx) {
                    for (ll ci = 0; ncv + ncx + ci <= cv + cx; ++ci) {
                        if (ci + (cv + cx - ncv - ncx - ci) * 50 == (cv - ncv) * 5 + (cx - ncx) * 10) {
                            broke = true;
                            break;
                        }
                    }
                    if (broke) {
                        break;
                    }
                }
                if (broke) {
                    break;
                }
            }
            if (broke) {
                break;
            }
            ll cn = max(-1LL, n - cv - cx);
            ans += (cn + 1);
        }
    }

    cout << ans << "\n";

    return 0;
}