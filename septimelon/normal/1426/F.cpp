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
const ll MOD = 1000000007;

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll cmul(ll a, ll b) {
    return (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0LL) {
        d += MOD - 1LL;
    }
    if (d == 0) {
        return 1LL;
    }
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

ll fit(string cs) {
    int cvop = 0;
    for (int i = 0; i < 3; ++i) {
        if (cs[i] == '?') {
            ++cvop;
        }
        else if (cs[i] != 'a' + i) {
            return -1;
        }
    }
}

void upd(map<string, ll>& cou, string cs, ll v) {
    if (cou.count(cs) == 0) {
        cou[cs] = v;
    }
    else {
        add(cou[cs], v);
    }
}

ll getv(map<string, ll>& cou, string cs) {
    if (cou.count(cs) == 0) {
        return 0LL;
    }
    return cou[cs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll k = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            ++k;
        }
    }

    map<string, ll> cou;
    cou[""] = 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            upd(cou, "a", 1);
        }
        if (s[i] == 'b') {
            upd(cou, "ab", getv(cou, "a"));
            upd(cou, "?b", getv(cou, "?"));
        }
        if (s[i] == 'c') {
            add(ans, cmul(getv(cou, "ab"), todeg(3, k)));
            add(ans, cmul(getv(cou, "a?"), todeg(3, k - 1)));
            add(ans, cmul(getv(cou, "?b"), todeg(3, k - 1)));
            add(ans, cmul(getv(cou, "??"), todeg(3, k - 2)));
        }
        if (s[i] == '?') {
            add(ans, cmul(getv(cou, "ab"), todeg(3, k - 1)));
            add(ans, cmul(getv(cou, "a?"), todeg(3, k - 2)));
            add(ans, cmul(getv(cou, "?b"), todeg(3, k - 2)));
            add(ans, cmul(getv(cou, "??"), todeg(3, k - 3)));
            upd(cou, "a?", getv(cou, "a"));
            upd(cou, "??", getv(cou, "?"));
            upd(cou, "?", 1);
        }
    }

    /*for (auto it = cou.begin(); it != cou.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }*/

    cout << ans << "\n";

    return 0;
}