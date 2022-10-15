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

ll psum(vector<ll>& vec)
{
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for (int i = 0; i + 1 < vec.size(); i++) {
        ans += (vec[i+1] - vec[i]) * (ll)(i + 1) *
            (ll)(vec.size() - i - 1);
    }
    return ans;
}

int n, m;
vector<ll> x[100005];
vector<ll> y[100005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c; scanf("%d", &c);
            x[c].push_back((ll)i);
            y[c].push_back((ll)j);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 100000; i++) {
        ans += psum(x[i]);
        ans += psum(y[i]);
    }
    printf("%lld", ans);
    return 0;
}