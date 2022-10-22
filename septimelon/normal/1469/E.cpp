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

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

void dec(string& cs, ll& val, int ci, ll cmu) {
    if (ci < 0) {
        return;
    }
    if (cs[ci] == '1') {
        cs[ci] = '0';
        add(val, MOD - todeg(cmu, cs.size() - 1 - ci));
    }
    else {
        cs[ci] = '1';
        add(val, todeg(cmu, cs.size() - 1 - ci));
        dec(cs, val, ci - 1, cmu);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        ll cmu = abs((ll)rnd() % 100000000) + 50000;
        //ll cad = rnd() % 100000000 + 500;
        set<ll> inc;
        inc.clear();
        ll cv = 0;
        for (int i = 0; i < k; ++i) {
            mul(cv, cmu);
            add(cv, s[i] - '0');
        }
        inc.insert(cv);
        ll cle = todeg(cmu, k - 1);
        for (int i = k; i < n; ++i) {
            add(cv, MOD - cle * (s[i - k] - '0'));
            mul(cv, cmu);
            add(cv, s[i] - '0');
            inc.insert(cv);
        }

        string cs = "";
        cs.clear();
        ll val = 0;
        val = 0;
        for (int i = 0; i < k; ++i) {
            cs += "1";
            add(val, todeg(cmu, i));
        }

        bool tru = false;
        tru = false;
        ll bval = val;
        for (int i = n + 1; i >= 0 && (val != bval || i == n + 1); --i) {
            if (inc.count(val) == 0) {
                tru = true;
                cout << "YES\n";
                for (int i = 0; i < k; ++i) {
                    cs[i] = '0' + (1 - (cs[i] - '0'));
                }
                cout << cs << "\n";
                break;
            }
            dec(cs, val, k - 1, cmu);
        }
        if (!tru) {
            cout << "NO\n";
        }
    }
}