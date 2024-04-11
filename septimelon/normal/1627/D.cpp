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

const ll MOD = 1000000007;
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

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void sub(ll& a, ll b) {
    add(a, MOD - b);
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll to_deg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = to_deg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

int gcd(int a, int b) {
    if (min(a, b) == 0) {
        return a + b;
    }
    return gcd(b % a, a);
}

void Solve() {
    int n;
    cin >> n;

    vector<bool> incl(1000001, false);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        incl[a] = true;
    }

    int ans = 0;

    for (int ne = 1000000; ne >= 1; --ne) {
        int cgcd = 0;
        for (int v = ne, cou = 1; v <= 1000000 && cgcd != 1; v += ne, ++cou) {
            if (incl[v]) {
                cgcd = gcd(cgcd, cou);
            }
        }
        if (cgcd == 1 && !incl[ne]) {
            incl[ne] = true;
            ++ans;
        }
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

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}