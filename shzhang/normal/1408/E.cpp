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

int uf[500005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

int m, n;
int a[100005], b[100005];

struct Edge {
    int st, elem;
};

bool operator<(Edge x, Edge y)
{
    return a[x.st] + b[x.elem] < a[y.st] + b[y.elem];
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m + n; i++) uf[i] = i;
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    vector<Edge> e;
    for (int i = 1; i <= m; i++) {
        int cnt; scanf("%d", &cnt);
        for (int j = 1; j <= cnt; j++) {
            int val; scanf("%d", &val);
            Edge ed; ed.st = i; ed.elem = val;
            e.push_back(ed);
        }
    }
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    ll ans = 0;
    for (int i = 0; i < e.size(); i++) {
        int x = e[i].st; int y = m + e[i].elem;
        if (fin(x) != fin(y)) {
            un(x, y);
        } else {
            ans += (ll)(a[x] + b[y - m]);
        }
    }
    printf("%lld", ans);
    return 0;
}