#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = (a + b);
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = todeg(x, d / 2);
    ans = mul(ans, ans);
    if (d % 2 == 1) {
        ans = mul(ans, x);
    }
    return ans;
}

vector<ll> fact, rfact;

void prep() {
    int mfact = 4000;
    fact.assign(mfact + 1, 1);
    rfact.assign(mfact + 1, 1);

    fact[0] = 1;
    for (int i = 1; i <= mfact; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }

    rfact[mfact] = todeg(fact[mfact], -1);
    for (int i = mfact; i > 0; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

vector<ll> poss(vector<int> allow) {
    vector<vector<ll>> mall(allow.size() + 1, vector<ll>(1801, 0));
    mall[0][0] = 1;
    if (allow.size() > 0) {
        mall[1][0] = 1;
    }
    for (int i = 2; i <= allow.size(); ++i) {
        for (int j = 0; j < 1801; ++j) {
            mall[i][j] = mall[i - 1][j];
            if (allow[i - 1] - allow[i - 2] == 1 && j > 0) {
                mall[i][j] = sum(mall[i][j], mall[i - 2][j - 1]);
            }
        }
    }
    return mall.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep();

    ll h, w, n;
    cin >> h >> w >> n;
    vector<bool> allowr(h, true), allowc(w, true);
    for (int i = 0; i < n * 2; ++i) {
        int cr, cc;
        cin >> cr >> cc;
        --cr;
        --cc;
        allowr[cr] = false;
        allowc[cc] = false;
    }

    vector<int> allr, allc;
    for (int i = 0; i < h; ++i) {
        if (allowr[i]) {
            allr.push_back(i);
        }
    }
    for (int i = 0; i < w; ++i) {
        if (allowc[i]) {
            allc.push_back(i);
        }
    }

    vector<ll> possr(poss(allr)), possc(poss(allc));
    ll ans = 0;
    for (int i = 0; i <= 1800; ++i) {
        for (int j = 0; i * 2 + j <= allr.size() && j * 2 + i <= allc.size(); ++j) {
            ll ccou = mul(possr[i], possc[j]);
            ccou = mul(ccou, mul(fact[allr.size() - i * 2], rfact[allr.size() - i * 2 - j]));
            ccou = mul(ccou, mul(fact[allc.size() - j * 2], rfact[allc.size() - j * 2 - i]));
            ans = sum(ans, ccou);
        }
    }

    cout << ans << "\n";

    return 0;
}