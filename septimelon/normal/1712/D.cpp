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

void Prep(int n) {
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
    //cout << "C[" << n << "," << k << "] = " << x << endl;
    return x;
}

int CalcScore(vector<int>& a) {
    int maxp{ 0 };
    int minv{ a[0] };
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        maxp = max(maxp, min(a[i], a[i - 1]));
        minv = min(minv, a[i]);
    }

    return min(maxp, minv * 2);
}

int MaxFirstKMins(vector<int> a, int k) {
    int n = a.size();
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        b.emplace_back(a[i], i);
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < k; ++i) {
        a[b[i].second] = 1000000000;
    }

    return CalcScore(a);
}

int MinN(vector<int>& a, int i) {
    if (i == 0) {
        return a[1];
    }
    if (i == a.size() - 1) {
        return a[a.size() - 2];
    }
    return min(a[i - 1], a[i + 1]);
}

int MinP(vector<int>& a, int i) {
    if (i == 0) {
        return 1;
    }
    if (i == a.size() - 1) {
        return a.size() - 2;
    }
    if (a[i - 1] < a[i + 1]) {
        return i - 1;
    }
    return i + 1;
}

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int score = MaxFirstKMins(a, k);

    if (k >= 1) {
        int maxi{ 0 };
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[maxi] || (a[i] == a[maxi] && MinN(a, i) < MinN(a, maxi))) {
                maxi = i;
            }
        }
        int oldi = MinP(a, maxi);
        int oldv = a[oldi];
        a[oldi] = 1000000000;
        score = max(score, MaxFirstKMins(a, k - 1));
        if (k >= 2) {
            a[oldi] = oldv;
            int mi = 0;
            for (int i = 1; i + 1 < n; ++i) {
                if (min(a[i], a[i + 1]) < min(a[mi], a[mi + 1]) || (min(a[i], a[i + 1]) == min(a[mi], a[mi + 1]) && a[i] + a[i + 1] < a[mi] + a[mi + 1])) {
                    mi = i;
                }
            }
            a[mi] = 1000000000;
            a[mi + 1] = 1000000000;
            score = max(score, MaxFirstKMins(a, k - 2));
        }
    }

    cout << score << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    //Prep(7000);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Solve();
    }

    return 0;
}