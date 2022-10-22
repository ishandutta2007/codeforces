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
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

vector<ll> numdel;

void prep() {
    numdel.assign(1000001, 1);
    vector<ll> cd(1000001, 1);
    for (ll i = 2; i < 1000001; ++i) {
        if (numdel[i] != 1) {
            continue;
        }
        for (ll j = i; j < 1000001; j += i) {
            cd[j] = 2;
        }
        ll cm = i * i;
        while (cm < 1000001LL) {
            for (ll j = cm; j < 1000001; j += cm) {
                ++cd[j];
            }
            cm *= i;
        }
        for (ll j = i; j < 1000001; j += i) {
            numdel[j] *= cd[j];
        }
    }
}

ll getval(int n, ll& tots) {
    if (n == 1) {
        return 1;
    }
    add(tots, getval(n - 1, tots));
    ll ans = tots;
    add(ans, numdel[n]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    prep();

    int n;
    cin >> n;
    ll tots = 0;
    cout << getval(n, tots) << endl;

    return 0;
}