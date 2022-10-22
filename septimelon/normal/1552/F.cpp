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

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
}

void sub(ll& a, ll b) {
    add(a, MOD + MOD - b);
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

vector<ll> fact, rfact;

void prep() {
    fact.assign(200001, 1);
    for (int i = 1; i < 200001; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact.assign(200001, 1);
    rfact.back() = todeg(fact.back(), -1);
    for (int i = 200000; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int indOfNext(int cx, const vector<int>& x) {
    int il{ -1 }, ir = x.size() - 1;
    while (ir - il > 1) {
        int im = (ir + il) / 2;
        if (x[im] < cx) {
            il = im;
        }
        else {
            ir = im;
        }
    }
    return ir;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    //prep();

    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }

    vector<ll> entloss(n + 1, 0);
    vector<ll> entpref(n + 1, 0);
    entloss[1] = x[0] - y[0];
    if (entloss[1] >= MOD) {
        entloss[1] -= MOD;
    }
    entpref[1] = entloss[1];
    for (int i = 2; i < n + 1; ++i) {
        ll curloss{ 0 };
        add(curloss, x[i - 1] - y[i - 1]);
        int nextl{ indOfNext(y[i - 1], x) };
        add(curloss, entpref[i - 1]);
        sub(curloss, entpref[nextl]);
        //cout << i << ": " << nextl << ", " << x[i - 1] - y[i - 1] << "\n";
        entloss[i] = curloss;
        entpref[i] = curloss;
        add(entpref[i], entpref[i - 1]);
    }

    ll ans{ 0 };
    add(ans, x.back() + 1LL);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1) {
            add(ans, entloss[i + 1]);
        }
    }

    cout << ans << "\n";

    return 0;
}