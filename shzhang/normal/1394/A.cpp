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

int n, d, m;
ll a[100005];

int main()
{
    scanf("%d%d%d", &n, &d, &m);
    vector<ll> muzzle, non_muzzle;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        if (a[i] > m) muzzle.push_back(a[i]);
        else non_muzzle.push_back(a[i]);
    }
    sort(muzzle.begin(), muzzle.end());
    sort(non_muzzle.begin(), non_muzzle.end());
    reverse(muzzle.begin(), muzzle.end());
    reverse(non_muzzle.begin(), non_muzzle.end());
    muzzle.insert(muzzle.begin(), 0);
    non_muzzle.insert(non_muzzle.begin(), 0);
    for (int i = 1; i < non_muzzle.size(); i++) {
        non_muzzle[i] += non_muzzle[i-1];
    }
    for (int i = 1; i < muzzle.size(); i++) {
        muzzle[i] += muzzle[i-1];
    }
    ll ans = 0;
    for (int cnt = 0; cnt < muzzle.size(); cnt++) {
        ll block_amt = cnt + (ll)max(cnt - 1, 0) * (ll)d;
        if (block_amt > n) continue;
        ans = max(ans, non_muzzle[min((ll)(n - block_amt), (ll)(non_muzzle.size() - 1))] + muzzle[cnt]);
    }
    printf("%lld", ans);
    return 0;
}