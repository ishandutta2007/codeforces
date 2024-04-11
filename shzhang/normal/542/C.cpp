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

int n;
int f[205];
int vis[205];

ll Gcd(ll a, ll b)
{
    if (b == 0LL) return a;
    return Gcd(b, a % b);
}

ll Lcm(ll a, ll b)
{
    return (a / Gcd(a, b)) * b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", f + i);
    vector<int> cyc_siz;
    int max_path_len = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        int cur = i; int step = 1;
        while (!vis[cur]) {
            vis[cur] = step;
            cur = f[cur];
            step++;
        }
        cyc_siz.push_back(step - vis[cur]);
        max_path_len = max(max_path_len, vis[cur] - 1);
    }
    ll ans = 1;
    for (int i = 0; i < cyc_siz.size(); i++) {
        ans = Lcm(ans, cyc_siz[i]);
    }
    ll rans = ans;
    while (rans < max_path_len) rans += ans;
    printf("%lld", rans);
    return 0;
}