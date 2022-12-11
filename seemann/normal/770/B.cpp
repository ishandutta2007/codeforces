#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

pair<int, ll> getSum(ll x) {
    int s = 0;
    ll y = x;
    while (y > 0) {
        s += y % 10;
        y /= 10;
    }
    return {s, x};
}
ll solve(ll x) {
    vector<int> digits;
    ll y = x;
    while (y > 0) {
        digits.pb(y % 10);
        y /= 10;
    }
    ll pw = 1;
    vector<pair<int, ll>> ans;
    ans.pb(getSum(x));
    for (auto d : digits) {
        if (d != 0) {
            ans.pb(getSum(x - pw));
        }
        x -= d * pw;
        x += 9 * pw;
        pw *= 10;
    }
    sort(ans.begin(), ans.end());
    return ans.rbegin()->second;
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    ll x;
    cin >> x;
    cout << solve(x) << '\n';
    /*
    pair<int, ll> best = {0, 0};
    for (int x = 1; x <= 1000000; ++x) {
        pair<int, ll> cur = getSum(x);
        if (cur > best)
            best = cur;
        assert(solve(x) == best.second);
    }*/
    
    return 0;
}