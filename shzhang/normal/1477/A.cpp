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

ll Gcd(ll a, ll b)
{
    if (b == 0) return a;
    return Gcd(b, a % b);
}

void work()
{
    int n; ll k;
    scanf("%d%lld", &n, &k);
    vector<ll> x;
    for (int i = 0; i < n; i++) {
        ll a; scanf("%lld", &a); x.push_back(a);
    }
    sort(x.begin(), x.end());
    ll curgcd = x[1] - x[0];
    for (int i = 1; i + 1 < n; i++) {
        curgcd = Gcd(curgcd, x[i + 1] - x[i]);
    }
    printf("%s\n", (((k % curgcd) + curgcd) % curgcd ==
        ((x[0] % curgcd) + curgcd) % curgcd) ? "YES" : "NO");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i  =1; i <= t; i++) work();
    return 0;
}