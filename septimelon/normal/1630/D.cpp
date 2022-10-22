#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
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

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

const ll MAXF = 2000500;

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Solve() {
    int n, m;
    cin >> n >> m;
    ll abss{ 0 };
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        abss += abs(a[i]);
    }
    ll b;
    cin >> b;
    for (int i = 1; i < m; ++i) {
        ll c;
        cin >> c;
        b = gcd(b, c);
    }

    if (b == 1) {
        cout << abss << "\n";
        return;
    }

    vector<ll> minh(b, INFL);
    vector<bool> isn(b, false);
    for (int i = 0; i < b; ++i) {
        for (int j = i; j < n; j += b) {
            minh[i] = min(minh[i], abs(a[j]));
            if (a[j] < 0) {
                isn[i] = !isn[i];
            }
        }
    }

    ll sump{ 0 }, sumn{ 0 };
    for (int i = 0; i < b; ++i) {
        //cout << isn[i] << ": " << minh[i] << "\n";
        if (isn[i]) {
            sumn += minh[i];
        }
        else {
            sump += minh[i];
        }
    }

    cout << max(abss - sumn * 2, abss - sump * 2) << "\n";
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