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

int n, d;
int x[1005], y[1005];
int uf[1005];
int siz[1005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b; siz[b] += siz[a];
}

void solve(int m)
{
    for (int i = 1; i <= n; i++) {
        uf[i] = i; siz[i] = 1;
    }
    for (int i = 1; i <= m; i++) un(x[i], y[i]);
    int comps = 0;
    vector<int> sizes;
    for (int i = 1; i <= n; i++) {
        if (fin(i) == i) {
            comps++; sizes.push_back(siz[i]);
        }
    }
    sort(sizes.begin(), sizes.end());
    reverse(sizes.begin(), sizes.end());
    int ans = 0;
    for (int i = 0; i < comps - n + m + 1; i++) {
        ans += sizes[i];
    }
    ans--;
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= d; i++) scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= d; i++) {
        solve(i);
    }
    return 0;
}