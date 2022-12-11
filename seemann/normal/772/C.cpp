#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 2e5 + 100;
const int MAXD = 1000;

bool f[MAXN];
int g[MAXN];
int dp[MAXN];
int pr[MAXN];
int inv[MAXN];
vector<int> r[MAXN];

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    cin.sync_with_stdio(0);
    cin >> n >> m;
    forn(i, n) {
        int x;
        cin >> x;
        if (x == 0)
            x += m;
        f[x] = true;
    }
    vector<int> divs;
    for (int i = 1; i <= m; ++i) {
        ll x = 0, y = 0;
        g[i] = gcd(i, m, x, y);
        x %= m;
        inv[i] = x;
        if (x < 0)
            inv[i] = (m + x) % m;
        if (!f[i])
            r[g[i]].push_back(i);
        if (g[i] == i) {
            divs.pb(i);
        }
    }
    int k = divs.size();
    for (int i = k - 1; i >= 0; --i) {
        int d = divs[i];
        dp[d] = 0;
        pr[d] = -1;
        for (int j = k - 1; j > i; --j) {
            int q = divs[j];
            if (q % d == 0) {
                if (dp[d] < dp[q]) {
                    dp[d] = dp[q];
                    pr[d] = q;
                }
            }
        }
        dp[d] += r[d].size();
    }
    cout << dp[1] << '\n';
    vector<int> ans = {1};
    for (int g = 1; g != -1; g = pr[g]) {
        for (auto x : r[g])
            ans.pb(x);
        vector<int> cur = r[g];
        forn(i, cur.size()) {
            cur[i] /= g;
        }
    }
    assert(ans.size() == dp[1] + 1);
    for (int i = 1; i < ans.size(); ++i) {
        int a = ans[i];
        int b = ans[i - 1];
        ll mul = g[a] / g[b];

        a /= g[a];
        mul = (((ll)inv[b]) * mul) % m * ((ll)a) % m;
        cout << mul << ' ';
    }

    return 0;
}