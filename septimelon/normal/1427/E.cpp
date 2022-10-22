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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int highdig(ll x) {
    int ans = 0;
    while (x > 0LL) {
        x /= 2LL;
        ++ans;
    }
    return ans;
}

ll umen(ll x, vector<ll>& ea, vector<ll>& eb, vector<char>& ec) {
    ll cx = x;
    ll highdigx = 1;
    while (highdigx * 2LL <= x) {
        highdigx *= 2LL;
    }
    while (cx % highdigx != 0LL) {
        ea.push_back(cx);
        eb.push_back(cx);
        ec.push_back('+');
        cx *= 2LL;
    }
    
    ea.push_back(x);
    ea.push_back(x);
    eb.push_back(cx);
    eb.push_back(cx);
    ec.push_back('+');
    ec.push_back('^');
    ll y2 = cx + x;
    ll y3 = (cx ^ x);

    ea.push_back(y2);
    eb.push_back(y3);
    ec.push_back('^');
    cx = (y2 ^ y3);

    while (highdig(cx) > highdig(x)) {
        ll ccx = x;
        while (highdig(ccx) < highdig(cx)) {
            ea.push_back(ccx);
            eb.push_back(ccx);
            ec.push_back('+');
            ccx *= 2LL;
        }
        ea.push_back(cx);
        eb.push_back(ccx);
        ec.push_back('^');
        cx ^= ccx;
    }

    while (highdig(cx) < highdig(x)) {
        ea.push_back(cx);
        eb.push_back(cx);
        ec.push_back('+');
        cx *= 2LL;
    }

    ea.push_back(x);
    eb.push_back(cx);
    ec.push_back('^');

    while ((x ^ cx) % 2 == 0) {
        cx = cx;
    }

    return (x ^ cx);
}

ll trie(ll x, vector<ll>& ea, vector<ll>& eb, vector<char>& ec) {
    ea.push_back(x);
    eb.push_back(x);
    ec.push_back('+');
    ll y1 = x * 2LL;

    ea.push_back(x);
    eb.push_back(y1);
    ec.push_back('+');
    ll y2 = x + y1;

    ea.push_back(y1);
    eb.push_back(y1);
    ec.push_back('+');
    ea.push_back(y2);
    eb.push_back(y1 * 2LL);
    ec.push_back('^');
    ll y3 = (y2 ^ (2 * y1));

    ea.push_back(y2);
    eb.push_back(y3);
    ec.push_back('+');
    ll y4 = y2 + y3;

    ea.push_back(2 * y1);
    eb.push_back(y4);
    ec.push_back('^');

    for (ll cd = 2LL; x > 1LL; cd *= 2LL) {
        //cout << x << " ";
        ea.push_back(x);
        eb.push_back(cd);
        ec.push_back('^');
        ea.push_back(cd);
        eb.push_back(cd);
        ec.push_back('+');
        x ^= cd;
    }

    return 1LL;
}

void solve() {
    ll x;
    cin >> x;

    vector<ll> ea, eb;
    vector<char> ec;
    while (x > 1LL) {
        if ((x & (x + 1LL)) > 0LL) {
            //cout << "umen";
            x = umen(x, ea, eb, ec);
        }
        else {
            //cout << "trie";
            x = trie(x, ea, eb, ec);
        }
    }

    cout << ea.size() << "\n";
    for (int i = 0; i < ea.size(); ++i) {
        cout << ea[i] << " " << ec[i] << " " << eb[i] << "\n";
    }
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);*/

    int t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}