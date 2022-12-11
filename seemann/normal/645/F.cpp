#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 2e5 + 100;
const int MAXM = 1e6 + 100;

bool prime[MAXM];
int dv[MAXM];
ll c[MAXN];
ll fact[MAXN];
ll MOD = 1e9 + 7;
int nd[MAXM];
int ans[MAXM];
int old[MAXM];
ll mpow(ll x, ll d) {
    if (d == 0)
        return 1;
    if (d % 2 == 0) {
        ll h = mpow(x, d / 2);
        return h * h % MOD;
    }
    return x * mpow(x, d - 1) % MOD;
}
ll inv(ll x) {
    return mpow(x, MOD - 2);
}
vector<int> divs[MAXM];
void norm(int & a) {
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}
void norm(ll & a) {
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}

int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    for (int i = 2; i < MAXM; ++i) {
        prime[i] = true;
    }
    for (int i = 2; i < MAXM; ++i) {
        if (!prime[i])
            continue;
        for (int j = i + i; j < MAXM; j += i) {
            prime[j] = false;
            dv[j] = i;
        }
    }
    divs[1] = {1};
    for (int i = 2; i < MAXM; ++i) {
        if (prime[i]) {
            divs[i] = {i, 1};
            continue;
        }
        int d = dv[i];
        int p = i;
        int c = 0;
        while (p % d== 0) {
            p /= d;
            c++;
        }
        int pw = 1;
        forn(_, c + 1) {
            for (auto x : divs[p]) {
                divs[i].pb(x * pw);
            }
            pw *= d;
        }
        sort(divs[i].begin(), divs[i].end());
        reverse(divs[i].begin(), divs[i].end());
    
    }
    
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    fact[0] = 1;
    forn(i, MAXN - 1) {
        fact[i + 1] = fact[i] * (i + 1) % MOD;
    }
    forn(i, MAXN - 1) {
        if (i < k)
            c[i] = 0;
        else {
            c[i] = fact[i] * inv(fact[i - k]) % MOD * inv(fact[k]) % MOD;
        }
    }
    forn(i, n) {
        int a;
        scanf("%d", &a);
        for (auto d : divs[a]) {
            nd[d]++;
        }
    }
    forn(i, MAXM) {
        ans[i] = c[nd[i]];
    }
    ll res = 0;
    for (int i = MAXM - 1; i >= 1; --i) {
        res += ((ll)ans[i]) * i;
        res %= MOD;
        for (auto d : divs[i]) {
            if (d == i)
                continue;
            ans[d] -= ans[i];
            if (ans[d] < 0)
                ans[d] += MOD;
        }
    }
    forn(i, q) {
        int C;
        scanf("%d", &C);
        for (auto d : divs[C]) {
            old[d] = ans[d];
        }
        for (auto d : divs[C]) {
            ans[d] += -c[nd[d]] + c[nd[d] + 1];
            norm(ans[d]);
            res += ((ll)(-old[d] + ans[d])) * d % MOD;
            norm(res);
            nd[d]++;
            for (auto d2 : divs[d]) {
                if (d2 == d)
                    continue;
                ans[d2] += old[d] - ans[d];
                norm(ans[d2]);
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}