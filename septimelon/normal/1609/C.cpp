#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

vector<bool> isp;

void Prep() {
    isp.assign(1000010, true);
    isp[0] = isp[1] = false;
    for (ll i = 2; i <= 1000009; ++i) {
        if (isp[i]) {
            for (ll j = i * i; j < 1000010; j += i) {
                isp[j] = false;
            }
        }
    }
}

void Solve() {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!isp[a[i]]) {
            continue;
        }
        ll cl = 1;
        for (int li = i - e; li >= 0; li -= e) {
            if (a[li] != 1) {
                break;
            }
            ++cl;
        }
        ll cr = 1;
        for (int ri = i + e; ri < n; ri += e) {
            if (a[ri] != 1) {
                break;
            }
            ++cr;
        }
        ans += cl * cr - 1;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    Prep();

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}