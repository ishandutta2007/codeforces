#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll pref(ll x) {
    ll a = x * (x + 1) / 2;
    if (x % 2) {
        a -= x;
    }
    a = (a - x / 2) / 2;
    if (x % 2) {
        a += x;
    }
    return x * (x + 1) / 2 - 2 * a;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll l, r;
        cin >> l >> r;
        cout << pref(r) - pref(l - 1) << "\n";
    }
}