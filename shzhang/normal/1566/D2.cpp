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
#include <map>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m;

#define lowbit(x) ((x)&(-(x)))

ll rquery(ll* arr, int v)
{
    ll ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(ll* arr, int loc, ll val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= m) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

ll query(ll* arr, int l, int r)
{
    return rquery(arr, r) - rquery(arr, l-1);
}

ll table[305][305];
int a[90005];
int a2[90005];
map<int, vector<pair<int, int> > > spots;

void work()
{
    scanf("%d%d", &n, &m);
    set<int> sights;
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", a + i);
        a2[i] = a[i];
        sights.insert(a[i]);
    }
    sort(a2 + 1, a2 + n * m + 1);
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            int idx = (r - 1) * m + c;
            spots[a2[idx]].push_back(make_pair(r, -c));
        }
    }
    while (!sights.empty()) {
        int cur = *sights.begin();
        sights.erase(sights.begin());
        sort(spots[cur].begin(), spots[cur].end());
        reverse(spots[cur].begin(), spots[cur].end());
    }
    int ans = 0;
    for (int i = 1; i <= n * m; i++) {
        vector<pair<int, int> >& vec = spots[a[i]];
        pair<int, int> pr = vec.back();
        vec.pop_back();
        ans += rquery(table[pr.first], -pr.second);
        modify(table[pr.first], -pr.second, 1);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            table[i][j] = 0;
        }
    }
    spots.clear();
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}