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

    int n, k;
    cin >> n >> k;

    int iters = (n - 1) / (k - 1) + 1;

    vector<int> col(n * k); /// colour
    vector<int> ns(n * k); /// next same
    vector<bool> leg(n, true); /// legal
    vector<int> last(n, INF);
    for (int i = 0; i < n * k; ++i) {
        cin >> col[i];
        --col[i];
    }
    for (int i = n * k - 1; i >= 0; --i) {
        ns[i] = last[col[i]];
        last[col[i]] = i;
    }

    vector<int> ansa(n), ansb(n);
    for (int q = 0; q < iters; ++q) {
        int cli{ -1 }, cri{ INF };
        for (int i = 0; i < n * k; ++i) {
            int c = col[i];
            if (i == cri) {
                ansa[c] = cli + 1;
                ansb[c] = cri + 1;
                leg[c] = false;
                cri = INF;
                continue;
            }
            if (leg[c]) {
                if (ns[i] < cri) {
                    cli = i;
                    cri = ns[i];
                }
                continue;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ansa[i] << " " << ansb[i] << "\n";
    }

    return 0;
}