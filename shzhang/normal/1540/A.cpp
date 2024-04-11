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

void work()
{
    int n; scanf("%d", &n);
    vector<ll> vals;
    for (int i = 1; i <= n; i++) {
        ll x; scanf("%lld", &x);
        vals.push_back(x);
    }
    sort(vals.begin(), vals.end());
    ll ans = vals[n-1];
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ans -= vals[i] * i - cur;
        cur += vals[i];
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}