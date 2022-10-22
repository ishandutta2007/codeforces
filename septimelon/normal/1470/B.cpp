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

vector<int> prim;

void prep(ll n) {
    vector<bool> isp(n + 1, true);
    for (ll i = 2; i <= n; ++i) {
        if (!isp[i]) {
            continue;
        }
        prim.push_back(i);
        for (ll j = i * i; j <= n; j += i) {
            isp[j] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int mosts = 0;
    map<vector<int>, int> vto;
    vto.clear();
    for (int i = 0; i < n; ++i) {
        int ca = a[i];
        vector<int> cpri;
        for (int j = 0; prim[j] * prim[j] <= ca; ++j) {
            if (ca % prim[j] != 0) {
                continue;
            }
            int cc = 0;
            while (ca % prim[j] == 0) {
                ++cc;
                ca /= prim[j];
            }
            if (cc % 2 == 1) {
                cpri.push_back(prim[j]);
            }
        }
        if (ca != 1) {
            cpri.push_back(ca);
        }
        if (vto.count(cpri) == 0) {
            vto[cpri] = 1;
        }
        else {
            ++vto[cpri];
        }
        mosts = max(mosts, vto[cpri]);
    }

    int megas = 0;
    for (auto it = vto.begin(); it != vto.end(); ++it) {
        if (it->second % 2 == 0 || it->first.empty()) {
            megas += it->second;
        }
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        ll w;
        cin >> w;
        if (w == 0) {
            cout << mosts << "\n";
        }
        else {
            cout << max(mosts, megas) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep(1000000);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }
}