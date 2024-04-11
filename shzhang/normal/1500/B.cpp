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

int n, m; ll k;
int a[500005], b[500005];
ll mod_val[1000005];
int aloc[1000005], bloc[1000005];

ll nmgcd, nmlcm;

#define safemod(x) (((x) % nmlcm + nmlcm) % nmlcm)

ll Gcd(ll A, ll B)
{
    if (B == 0) return A;
    return Gcd(B, A % B);
}

void exgcd(ll A, ll B, ll& x, ll& y)
{
    if (B == 0) {
        x = 1; y = 0;
        //printf("%lld %lld %lld %lld\n", A, B, x, y);
        return;
    }
    ll nx, ny; exgcd(B, A % B, nx, ny);
    x = ny;
    y = nx - (A / B) * ny;
    //printf("%lld %lld %lld %lld\n", A, B, x, y);
}

ll cnt(ll days)
{
    ll ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (mod_val[i] != -1) {
            ans += days / nmlcm + (days % nmlcm >= mod_val[i] ? 1 : 0);
        }
    }
    return days + 1 - ans;
}

ll crt_solve(ll A, ll B, ll M, ll N)
{
    ll x, y;
    exgcd(M, N, x, y);
    return (safemod(safemod(A * N) * y) + safemod(safemod(B * M) * x)) % nmlcm;
}

int main()
{
    //printf("%lld %lld\n", A, B);
    for (int i = 1; i <= 1000000; i++) aloc[i] = bloc[i] = -1;
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        aloc[a[i]] = i - 1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
        bloc[b[i]] = i - 1;
    }
    nmgcd = Gcd(n, m);
    nmlcm = ((ll)n * (ll)m) / nmgcd;
    for (int i = 1; i <= 1000000; i++) {
        mod_val[i] = -1;
        if (aloc[i] >= 0 && bloc[i] >= 0) {
            if (aloc[i] % nmgcd == bloc[i] % nmgcd) {
                int subval = aloc[i] % nmgcd;
                int na = aloc[i] - subval;
                int nb = bloc[i] - subval;
                ll res = crt_solve(na / nmgcd, nb / nmgcd, n / nmgcd, m / nmgcd);
                mod_val[i] = (res * nmgcd + subval) % nmlcm;
            }
        }
        //if (mod_val[i] != -1) printf("%d %lld\n", i, mod_val[i]);
    }
    //debug("HERE");
    ll l = 0, r = 9000000000000000000LL;
    while (l < r) {
        ll mid = (l + r) / 2LL;
        if (cnt(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld", l + 1);
    return 0;
}