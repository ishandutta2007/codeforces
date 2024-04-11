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

ll s, x;

int main()
{
    scanf("%lld%lld", &s, &x);
    ll s_high = s >> 20LL;
    ll s_low = s & ((1 << 20LL) - 1);
    ll x_high = x >> 20LL;
    ll x_low = x & ((1 << 20LL) - 1);
    ll no_carry = 0, carry = 0;
    for (ll a_high = 0; a_high < (1LL << 20LL); a_high++) {
        ll b_high = a_high ^ x_high;
        if (a_high + b_high == s_high) no_carry++;
        if (a_high + b_high + 1LL == s_high) carry++;
    }
    ll ans = 0;
    for (ll a_low = 0; a_low < (1LL << 20LL); a_low++) {
        ll b_low = a_low ^ x_low;
        if (a_low + b_low == s_low) ans += no_carry;
        if (a_low + b_low == s_low + (1LL << 20LL)) ans += carry;
    }
    if (s == x) ans -= 2LL;
    printf("%lld", ans);
    return 0;
}