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

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<ll> open_at_st(n, 0);
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            open_at_st[i] = open_at_st[i - 1] + c[i - 1];
        }
        else {
            open_at_st[i] = open_at_st[i - 1] - c[i - 1];
        }
    }

    ll ans{ 0 };
    for (int li = 0; li < n; li += 2) {
        ll min_op{ 0 }, cur_op{ -c[li] };
        for (int ri = li + 1; ri < n; ri += 2) {
            cur_op += c[ri - 1];
            ll betw = open_at_st[ri] - open_at_st[li] - c[li];
            ll cl{ c[li] }, cr{ c[ri] };
            cl -= max(min_op - 1, 0LL);
            betw += max(min_op - 1, 0LL);
            if (betw < 0LL) {
                cl += betw;
            }
            else if (betw > 0LL) {
                cr -= betw;
            }
            //cout << li << " " << ri << " " << max(0LL, min(cl, cr)) << endl;

            ans += max(0LL, min(cl, cr));

            cur_op -= c[ri];
            min_op = max(min_op, -cur_op);
        }
    }

    cout << ans << "\n";

    return 0;
}