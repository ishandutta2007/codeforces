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

ll count_steps(vector<int> cur, const vector<int>& fin) {
    int cc{ 0 }, cf{ 0 };
    for (int i = 0; i < cur.size(); ++i) {
        cc += cur[i];
        cf += fin[i];
    }
    if (cc != cf) {
        return INFL;
    }
    ll ans{ 0 };
    ll li{ 0 }, ri{ 0 };
    while (li < cur.size()) {
        if (cur[li] == 0) {
            ++li;
            continue;
        }
        while (fin[ri] == 0) {
            ++ri;
        }
        ans += abs(ri - li);
        ++li;
        ++ri;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = (a[i] & 1);
    }

    ll best{ INFL };
    vector<int> poss(n);
    for (int i = 0; i < n; ++i) {
        poss[i] = (i & 1);
    }
    best = count_steps(a, poss);
    for (int i = 0; i < n; ++i) {
        poss[i] ^= 1;
    }
    best = min(best, count_steps(a, poss));
    if (best == INFL) {
        best = -1;
    }
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}