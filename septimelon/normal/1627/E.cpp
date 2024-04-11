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

struct Ladder {
    ll a, b, c, d;
    ll h;
};

void InsertLadder(vector<pair<ll, ll>>& ladd_vec, ll new_x, ll new_h, ll x_i) {
    bool can_ins = true;

    while (!ladd_vec.empty() && can_ins) {
        assert(new_x >= ladd_vec.back().first);

        ll dxh = (new_x - ladd_vec.back().first) * x_i;
        if (new_h - dxh >= ladd_vec.back().second) {
            ladd_vec.pop_back();
            continue;
        }
        if (new_h + dxh <= ladd_vec.back().second) {
            can_ins = false;
            break;
        }
        break;
    }

    if (can_ins) {
        ladd_vec.push_back({ new_x, new_h });
    }
}

const int MAXN = 100500;

ll x[MAXN];
vector<pair<ll, ll>> flv[MAXN];
Ladder l[MAXN];
int ind[MAXN];

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        flv[i].clear();
    }

    for (int i = 0; i < k; ++i) {
        cin >> l[i].a >> l[i].b >> l[i].c >> l[i].d >> l[i].h;
        --l[i].a;
        --l[i].c;
    }
    iota(ind, ind + k, 0);
    sort(ind, ind + k, [&](const int& a, const int& b) {if (l[a].c != l[b].c) return l[a].c < l[b].c; return l[a].d < l[b].d; });

    //vector<vector<pair<ll, ll>>> flv(n);
    flv[0].push_back({ 1, 0LL });

    for (int i = 0; i < k; ++i) {
        Ladder cl = l[ind[i]];
        if (flv[cl.a].empty()) {
            continue;
        }
        ll maxh = -INFL;
        auto ub = upper_bound(flv[cl.a].begin(), flv[cl.a].end(), pair<ll, ll>{ cl.b, 0LL });
        if (ub != flv[cl.a].end()) {
            maxh = (*ub).second - abs((*ub).first - cl.b) * x[cl.a];
        }
        if (ub != flv[cl.a].begin()) {
            --ub;
            maxh = max(maxh, (*ub).second - abs(cl.b - (*ub).first) * x[cl.a]);
        }
        maxh += cl.h;
        InsertLadder(flv[cl.c], cl.d, maxh, x[cl.c]);
    }

    if (flv[n - 1].empty()) {
        cout << "NO ESCAPE\n";
        return;
    }
    cout << (0LL - flv[n - 1].back().second + (m - flv[n - 1].back().first) * x[n - 1]) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    for (int i = 0; i < MAXN; ++i) {
        flv[i].reserve(100);
    }

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}