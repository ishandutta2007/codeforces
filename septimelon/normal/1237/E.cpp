#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = (a + b);
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

struct Val {
    ll same, othe;
    bool ismins;

    bool operator<(const Val& v) const {
        if (same != v.same) {
            return same < v.same;
        }
        if (othe != v.othe) {
            return othe < v.othe;
        }
        return ismins < v.ismins;
    }

    void print() {
        cout << "{" << same << "," << othe << "," << ismins << "}";
    }
};

ll att(Val val, map<Val, ll>& vals) {
    if (val.same == 0 && val.othe == 0) {
        return 1LL;
    }
    if (val.same < 0LL || val.othe < 0LL || abs(val.same - val.othe) > 1 || (!val.ismins && val.same > val.othe) || (val.ismins && val.same < val.othe)) {
        return 0LL;
    }
    if (vals.count(val) > 0) {
        return vals[val];
    }

    //val.print();

    ll ans = 0LL;
    ll totch = sum(val.same - 1LL, val.othe);
    ll mins = 1;
    while (mins * 3 + 1 < totch) {
        mins = mins * 2 + 1;
    }
    for (ll ls = mins; totch - ls >= mins; ++ls) {
        Val left, righ;
        if (val.ismins && ls % 2 == 0) {
            left = { ls / 2, ls / 2, false };
            righ = { val.same - ls / 2 - 1, val.othe - ls / 2, false };
            ans = sum(ans, mul(att(left, vals), att(righ, vals)));
        }
        if (!val.ismins && ls % 2 == 1) {
            left = { (ls + 1) / 2, ls / 2, true };
            righ = { val.same - ls / 2 - 1, val.othe - (ls + 1) / 2, false };
            ans = sum(ans, mul(att(left, vals), att(righ, vals)));
        }
    }

    //cout << ans << " ";

    vals[val] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    /*map<Val, ll> vals;
    vals[{ 1, 0, true }] = 1;
    vals[{ 1, 0, false }] = 0;
    vals[{ 1, 1, true }] = 0;
    vals[{ 1, 1, false }] = 1;
    vals[{ 1, 2, true }] = 0;
    vals[{ 1, 2, false }] = 0;
    vals[{ 2, 1, true }] = 0;
    vals[{ 2, 1, false }] = 0;

    cout << sum(att({ (n + 1) / 2, n / 2, true }, vals), att({ n / 2, (n + 1) / 2, false }, vals)) << "\n";*/

    int ci = 1;
    int no = 0;
    while (ci < n) {
        if (no % 2 == 0) {
            ++ci;
        }
        else {
            ci *= 2;
            if (no == 3) {
                --ci;
            }
        }
        no = (no + 1) % 4;
    }

    if (ci == n) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}