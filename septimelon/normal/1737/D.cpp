#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")
#pragma unroll

#include <algorithm>
#include <bit>
#include <bitset>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-9;
const ld INFLD = 1e20;
const ll INFL = 1e17;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd(643896);

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

ll ToDeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = ToDeg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

vector<ll> fact, rfact;

//vector<ll> prim;

void Prep(ll n) {
    //vector<char> isp(n, true);
    //for (ll i = 2; i < n; ++i) {
    //    if (isp[i]) {
    //        prim.push_back(i);
    //        for (ll j = i * i; j < n; j += i) {
    //            isp[j] = false;
    //        }
    //    }
    //}
    fact.assign(n, 1);
    rfact.assign(n, 1);
    for (int i = 1; i < n; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact[n - 1] = ToDeg(fact[n - 1], -1);
    for (int i = n - 1; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(ll n, ll k) {
    ll x = fact[n];
    if (k < 0 || k > n) {
        return 0;
    }
    mul(x, rfact[k]);
    mul(x, rfact[n - k]);
    return x;
}

int n;
vector<vector<int>> r;

vector<int> GetDist(int u0) {
    vector<int> dist(n, INF);
    dist[u0] = 0;

    queue<int> bfs;
    bfs.push(u0);

    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        int nd{ dist[u] + 1 };
        for (int v : r[u]) {
            if (dist[v] > nd) {
                dist[v] = nd;
                bfs.push(v);
            }
        }
    }

    return dist;
}

void Solve() {
    int m;
    cin >> n >> m;
    r.assign(n, {});
    vector<int> u, v;
    vector<ll> w;
    for (int i = 0; i < m; ++i) {
        int cu, cv;
        cin >> cu >> cv;
        --cu;
        --cv;
        u.push_back(cu);
        v.push_back(cv);
        ll cw;
        cin >> cw;
        w.push_back(cw);
        r[cu].push_back(cv);
        r[cv].push_back(cu);
    }

    vector<vector<int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = GetDist(i);
    }
    vector<int> ds(n);
    for (int i = 0; i < n; ++i) {
        ds[i] = d[i][0] + d[i][n - 1];
    }

    ll ans{ INFL };
    for (int i = 0; i < m; ++i) {
        int pl{ INF };
        int cu{ u[i] }, cv{ v[i] };
        pl = min(pl, d[cu][0] + d[cv][n - 1] + 1);
        pl = min(pl, d[cv][0] + d[cu][n - 1] + 1);
        for (int j = 0; j < n; ++j) {
            pl = min(pl, d[cu][j] + ds[j] + 2);
            pl = min(pl, d[cv][j] + ds[j] + 2);
        }
        ans = min(ans, ll{ pl } * w[i]);
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

    //Prep(14000001);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Solve();
    }

    return 0;
}