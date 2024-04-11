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
const ll HALF = (MOD + 1LL) / 2LL;
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

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll CalsAns(int a, int b, vector<vector<ll>>& ans) {
    if (ans[a][b] == -1) {
        ans[a][b] = CalsAns(a - 1, b, ans);
        add(ans[a][b], CalsAns(a, b - 1, ans));
        mul(ans[a][b], HALF);
    }
    return ans[a][b];
}

void SolveEasy() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, -1));
    for (int i = 0; i <= n; ++i) {
        ans[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i][0] = k;
        add(ans[i][0], ans[i - 1][0]);
    }

    cout << CalsAns(m, n - m, ans) << "\n";
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

vector<ll> fact(1000001, 1), rfact(1000001, 1);

void Prep() {
    for (ll i = 1; i < 1000001; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact[1000000] = to_deg(fact[1000000], -1);
    for (ll i = 1000000; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(ll n, ll k) {
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll a = m, b = n - m;
    
    if (a == 0) {
        cout << "0\n";
        return;
    }
    else if (b == 0) {
        mul(a, k);
        cout << a << "\n";
        return;
    }
    
    ll ans = 0;
    ll znam = to_deg(HALF, b);
    for (int i = 0; i < a; ++i) {
        ll chis = a - i;
        mul(chis, znam);
        mul(chis, C(b - 1 + i, b - 1));
        add(ans, chis);
        mul(znam, HALF);
    }

    mul(ans, k);

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