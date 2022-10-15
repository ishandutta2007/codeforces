#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

ll n;
int ans = 0;
int digcnt;
ll pref[20];
ll pwr10[20];

#define div9(x) (((x) + 1000000LL * 998244353LL) / 998244353LL - 1000000LL)

ll count_pref(ll x, int digits)
{
    if (digits == 0) return n;
    ll Ans = 0;
    for (int i = digits; i < digcnt; i++) {
        Ans += pwr10[i - digits];
    }
    if (x < pref[digits]) {
        Ans += pwr10[digcnt - digits];
    } else if (x == pref[digits]) {
        Ans += n - x * pwr10[digcnt - digits] + 1;
    }
    //printf("? %lld %d %lld\n", x, digits, Ans);
    return Ans;
}

void dfs(ll x, int digits, int upto, ll presum)
{
    if (upto == digcnt) {
        if (x > pref[digits]) return;
        if (x == pref[digits] && digits < upto) {
            ll cursum = presum;
            for (ll nxt = pref[digits] * 10LL; nxt <= pref[digits + 1]; nxt++) {
                if (digits || nxt) {
                    dfs(nxt, digits + 1, upto, cursum + 1);
                    cursum += count_pref(nxt, digits + 1);
                }
            }
            return;
        }
    }

    if (digits == upto) {
        //printf("! %lld %d %d %lld\n", x, digits, upto, presum);
        ans -= div9(presum + 1LL - x);
        if (ans < 0) ans += MOD;
        if (ans >= MOD) ans -= MOD;
        return;
    }

    if (digits > 0) {
        ll mina = x * pwr10[upto - digits];
        ll maxa = mina + pwr10[upto - digits] - 1;
        ll mini = presum;
        ll maxi = presum + count_pref(x, digits);
        if (div9(maxi - mina) == div9(mini - maxa)) {
            ans -= mul(div9(maxi - mina) + MOD, pwr10[upto - digits] % MOD);
            if (ans < 0) ans += MOD;
            if (ans >= MOD) ans -= MOD;
            return;
        }
    }

    ll cursum = presum;
    for (ll nxt = x * 10LL; nxt < (x + 1LL) * 10LL; nxt++) {
        if (digits || nxt) {
            dfs(nxt, digits + 1, upto, cursum + 1);
            cursum += count_pref(nxt, digits + 1);
        }
    }
}

int main()
{
    pwr10[0] = 1LL;
    for (int i = 1; i <= 15; i++) {
        pwr10[i] = 10LL * pwr10[i-1];
    }
    scanf("%lld", &n);
    char tmp[20]; sprintf(tmp, "%lld", n);
    digcnt = strlen(tmp);
    ll tmp2 = n;
    for (int i = 0; i < digcnt; i++) {
        pref[digcnt - i] = tmp2;
        tmp2 /= 10LL;
    }
    for (int i = 1; i <= digcnt; i++) {
        dfs(0, 0, i, -1);
    }
    ans = mul(ans, 998244353);
    printf("%d", ans);
    return 0;
}