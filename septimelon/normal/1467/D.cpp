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
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD) {
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
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    ++k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> coe(k, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        coe[0][i] = 1;
    }
    for (int ck = 1; ck < k; ++ck) {
        coe[ck][0] = coe[ck - 1][1];
        coe[ck][n - 1] = coe[ck - 1][n - 2];
        for (int i = 1; i < n - 1; ++i) {
            add(coe[ck][i], coe[ck - 1][i - 1]);
            add(coe[ck][i], coe[ck - 1][i + 1]);
        }
    }
    /*for (int ck = k - 2; ck >= 0; --ck) {
        vector<ll> cv(n);
        for (int i = 0; i < n; ++i) {
            ll cva = 0;
            ll del = 0;
            if (i == 1) {
                add(cva, coe[ck + 1][0]);
            }
            if (i > 1) {
                del = coe[ck + 1][i - 1];
                if (coe[ck][i - 2] + coe[ck][i] != 0 && coe[ck][i - 2] + coe[ck][i] != MOD) {
                    mul(del, todeg(coe[ck][i - 2] + coe[ck][i], -1));
                    mul(del, coe[ck][i]);
                }
                else {
                    del = coe[ck][i];
                }
                add(cva, del);
            }
            if (i == n - 2) {
                add(cva, coe[ck + 1][n - 1]);
            }
            if (i < n - 2) {
                del = coe[ck + 1][i + 1];
                if (coe[ck][i + 2] + coe[ck][i] != 0 && coe[ck][i + 2] + coe[ck][i] != MOD) {
                    mul(del, todeg(coe[ck][i + 2] + coe[ck][i], -1));
                    mul(del, coe[ck][i]);
                }
                else {
                    del = coe[ck][i];
                }
                add(cva, del);
            }
            cv[i] = cva;
        }
        coe[ck] = cv;
    }*/

    vector<ll> totc(n, 0);
    for (int ck = k - 1; ck >= 0; --ck) {
        for (int i = 0; i < n; ++i) {
            ll del = coe[ck][i];
            mul(del, coe[k - 1 - ck][i]);
            add(totc[i], del);
        }
    }

    ll cura = 0;
    for (int i = 0; i < n; ++i) {
        ll cv = a[i];
        mul(cv, totc[i]);
        add(cura, cv);
    }

    for (int i = 0; i < q; ++i) {
        int ci;
        ll ca;
        cin >> ci >> ca;
        --ci;
        ll del = a[ci];
        mul(del, totc[ci]);
        add(cura, MOD - del);
        a[ci] = ca;
        del = ca;
        mul(del, totc[ci]);
        add(cura, del);
        cout << cura << "\n";
    }
}