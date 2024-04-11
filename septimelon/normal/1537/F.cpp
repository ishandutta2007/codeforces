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
const ll INFL = 2e18;
const int INF = 2e9 + 7;
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

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans{ todeg(x, d / 2) };
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

bool twoPartDFS(int cv, int cd, vector<int>& in_dol, vector<vector<int>>& r) {
    if (in_dol[cv] >= 0) {
        return (in_dol[cv] == cd);
    }

    in_dol[cv] = cd;

    bool result = true;
    for (int nv : r[cv]) {
        if (!twoPartDFS(nv, cd ^ 1, in_dol, r)) {
            result = false;
            break;
        }
    }

    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<vector<int>> r(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }

    vector<int> in_dol(n, -1);
    bool is_two_part = twoPartDFS(0, 0, in_dol, r);
    if (!is_two_part) {
        for (int i = 0; i < n; ++i) {
            in_dol[i] = 0;
        }
    }

    ll sumv[2]{ 0, 0 }, sumt[2]{ 0, 0 };
    for (int i = 0; i < n; ++i) {
        sumv[in_dol[i]] += v[i];
        sumt[in_dol[i]] += t[i];
    }

    if ((!is_two_part && ((sumv[0] - sumt[0]) & 1)) || 
        (is_two_part && ((sumv[0] - sumt[0]) != (sumv[1] - sumt[1])))) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}