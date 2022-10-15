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

ll l[505];
bool query[505];

int n, m;

ll make_query()
{
    printf("? ");
    for (int i = 1; i <= m; i++) {
        printf("%d", (int)query[i]);
    }
    printf("\n"); fflush(stdout);
    ll res; scanf("%lld", &res);
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    vector<pair<ll, int> > edges;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) query[j] = false;
        query[i] = true;
        ll res = make_query();
        l[i] = res; edges.push_back(make_pair(l[i], i));
    }
    sort(edges.begin(), edges.end());
    ll lastans = 0;
    for (int j = 1; j <= m; j++) query[j] = false;
    for (int i = 0; i < m; i++) {
        int curedge = edges[i].second;
        query[curedge] = true;
        ll res = make_query();
        if (res - lastans != l[curedge]) {
            query[curedge] = false;
        } else {
            lastans = res;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (query[i]) ans += l[i];
    }
    printf("! %lld", ans);
    return 0;
}