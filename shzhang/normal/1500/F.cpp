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

int n; ll C;
ll w[1000005];
bool hasw[1000005];
ll d[1000005];
ll ans[1000005];
ll anyd[1000005];

ll transa = 1, transb = 0;

static inline ll transform(ll x)
{
    return x * transa + transb;
}

static inline ll untransform(ll x)
{
    return (x - transb) / transa;
}

deque<pair<ll, ll> > que;

void make_min(ll minv)
{
    if (transa > 0) {
        while (!que.empty()) {
            if (transform(que[0].second) < minv) {
                que.pop_front();
            } else if (transform(que[0].first) < minv) {
                que[0].first = untransform(minv); break;
            } else {
                break;
            }
        }
    } else {
        while (!que.empty()) {
            if (transform(que.back().first) < minv) {
                que.pop_back();
            } else if (transform(que.back().second) < minv) {
                que.back().second = untransform(minv); break;
            } else {
                break;
            }
        }
    }
}

void make_max(ll maxv)
{
    transa = -transa;
    transb = -transb;
    make_min(-maxv);
    transa = -transa;
    transb = -transb;
}

int main()
{
    scanf("%d%lld", &n, &C);
    for (int i = 1; i <= n - 2; i++) scanf("%lld", w + i);
    que.push_back(make_pair(0, 1000000000000000000LL));
    for (int i = 1; i <= n - 2; i++) {
        make_max(w[i]);
        if (que.empty()) {
            printf("NO"); return 0;
        }
        ll minv = (transa > 0 ? transform(que.front().first) :
            transform(que.back().second));
        ll maxv = (transa > 0 ? transform(que.back().second) :
            transform(que.front().first));
        //printf("%lld %lld\n", minv, maxv);
        anyd[i] = minv;
        bool has0 = (minv == 0);
        hasw[i] = (maxv == w[i]);
        transa = -transa;
        transb = -transb + w[i];
        if (hasw[i]) {
            que.clear();
            transa = 1; transb = 0;
            que.push_back(make_pair(0, w[i]));
        } else if (!has0) {
            if (transa > 0) {
                que.push_back(make_pair(untransform(w[i]), untransform(w[i])));
            } else {
                que.push_front(make_pair(untransform(w[i]), untransform(w[i])));
            }
        }
    }
    if (que.empty()) {
        printf("NO"); return 0;
    }
    printf("YES\n");
    d[n - 2] = transform(que.front().first);
    for (int i = n - 3; i >= 0; i--) {
        if (d[i + 1] == w[i + 1]) {
            d[i] = anyd[i + 1];
        } else if (hasw[i + 1]) {
            d[i] = w[i+1];
        } else {
            d[i] = w[i+1] - d[i+1];
        }
    }
    /*for (int i = 0; i <= n - 2; i++) {
        printf("%lld ", d[i]);
    }
    printf("\n");*/
    ans[1] = 0;
    ans[2] = d[0];
    for (int i = 3; i <= n; i++) {
        if (w[i-2] == max(d[i-3], d[i-2])) {
            if (ans[i-2] < ans[i-1]) {
                ans[i] = ans[i-1] - d[i-2];
            } else {
                ans[i] = ans[i-1] + d[i-2];
            }
        } else {
            if (ans[i-2] > ans[i-1]) {
                ans[i] = ans[i-1] - d[i-2];
            } else {
                ans[i] = ans[i-1] + d[i-2];
            }
        }
    }
    ll minv = 0;
    for (int i = 1; i <= n; i++) {
        minv = min(minv, ans[i]);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] -= minv;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}