#define _CRT_SECURE_NO_WARNINGS

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

const ll MOD = 998244353;
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

vector<ll> prim;

void Prep(ll n) {
    vector<char> isp(n, true);
    for (ll i = 2; i < n; ++i) {
        if (isp[i]) {
            prim.push_back(i);
            for (ll j = i * i; j < n; j += i) {
                isp[j] = false;
            }
        }
    }
    //fact.assign(n, 1);
    //rfact.assign(n, 1);
    //for (int i = 1; i < n; ++i) {
    //    fact[i] = i;
    //    mul(fact[i], fact[i - 1]);
    //}
    //rfact[n - 1] = ToDeg(fact[n - 1], -1);
    //for (int i = n - 1; i > 0; --i) {
    //    rfact[i - 1] = i;
    //    mul(rfact[i - 1], rfact[i]);
    //}
}

ll C(ll n, ll k) {
    ll x = fact[n];
    if (k < 0 || k > n) {
        return 0;
    }
    mul(x, rfact[k]);
    mul(x, rfact[n - k]);
    //cout << "C[" << n << "," << k << "] = " << x << endl;
    return x;
}

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> div, step;
    for (ll cp : prim) {
        if (n % cp == 0) {
            div.push_back(cp);
            step.push_back(n / cp);
        }
    }

    if (div[0] == n) {
        ll sum{ 0 };
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        cout << sum << " ";
        for (int qq = 0; qq < q; ++qq) {
            int pos;
            ll nv;
            cin >> pos >> nv;
            --pos;
            sum -= a[pos];
            a[pos] = nv;
            sum += nv;
            cout << sum << " ";
        }
        cout << "\n";
        return;
    }

    priority_queue<pair<ll, pair<int, int>>> best;

    vector<vector<ll>> ss(div.size());
    for (int i = 0; i < div.size(); ++i) {
        int cp = div[i];
        for (int j = 0; j < step[i]; ++j) {
            ss[i].push_back(0);
            for (int k = j; k < n; k += step[i]) {
                ss[i][j] += a[k];
            }
            ss[i][j] *= step[i];
            best.push({ ss[i][j], {i, j} });
        }
    }

    cout << best.top().first << " ";

    for (int qq = 0; qq < q; ++qq) {
        int pos;
        ll nv;
        cin >> pos >> nv;
        --pos;
        for (int i = 0; i < div.size(); ++i) {
            int j = pos % step[i];
            ss[i][j] += (nv - a[pos]) * step[i];
            best.push({ ss[i][j], {i, j} });
        }
        a[pos] = nv;

        while (true) {
            auto tp = best.top().second;
            if (ss[tp.first][tp.second] != best.top().first) {
                best.pop();
                continue;
            }
            break;
        }

        cout << best.top().first << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    Prep(200001);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Solve();
    }

    return 0;
}