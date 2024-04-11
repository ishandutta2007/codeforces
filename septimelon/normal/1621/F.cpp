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

ll CalcGain(bool start_one, ll remo, ll remzb, int zones, int zb, int add_zb, priority_queue<ll> zeros, ll a, ll b, ll c) {
    bool nex_one = start_one;

    ll gain = 0LL;
    while (true) {
        if (nex_one) {
            nex_one = false;
            if (remo > 0) {
                gain += b;
                --remo;
            }
            else {
                break;
            }
        }
        else {
            nex_one = true;
            if (remo == 0 && zones > 0 && c < b) {
                --zones;
                ++remo;
                gain -= c;
            }
            else if (!zeros.empty()) {
                int cz = 0 - zeros.top();
                zeros.pop();
                gain += a;
                --cz;
                if (cz > 0) {
                    zeros.push(0 - cz);
                }
                else {
                    ++zones;
                }
            }
            else if (remzb > 0) {
                gain += a;
                --remzb;
                if (remzb == 0) {
                    zb += add_zb;
                }
            }
            else if (zones > 0 && c < b) {
                --zones;
                ++remo;
                gain -= c;
            }
            else if (remo > 0 && c < b && zb > 0) {
                --zb;
                gain -= c;
            }
            else {
                break;
            }
        }
    }

    return gain;
}

void Solve() {
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    
    ll remo{ 0 };
    ll remzb{ 0 };
    int zones{ 0 };
    int zb{ 0 }, add_zb{ 0 };
    priority_queue<ll> zeros;

    vector<int> cou;
    cou.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (cou.back() >= 0) {
                cou.push_back(0);
            }
            --cou.back();
        }
        else if (s[i] == '0') {
            if (cou.back() < 0) {
                cou.push_back(0);
            }
            ++cou.back();
        }
    }
    if (cou.back() < 0) {
        cou.push_back(0);
    }
    
    if (cou[0] > 1) {
        remzb += cou[0] - 1;
        ++add_zb;
    }
    else if (cou[0] == 1) {
        ++zb;
    }
    if (cou.back() > 1) {
        remzb += cou.back() - 1;
        ++add_zb;
    }
    else if (cou.back() == 1) {
        ++zb;
    }
    
    for (int i = 1; i < cou.size() - 1; ++i) {
        if (cou[i] < 0) {
            remo -= (cou[i] + 1);
        }
        else if (cou[i] == 1) {
            ++zones;
        }
        else {
            zeros.push(1 - cou[i]);
        }
    }

    ll ans = max(CalcGain(true, remo, remzb, zones, zb, add_zb, zeros, a, b, c), CalcGain(false, remo, remzb, zones, zb, add_zb, zeros, a, b, c));

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}