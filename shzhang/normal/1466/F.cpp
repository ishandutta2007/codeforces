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

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int uf[500005];
int goodcnt[500005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b; goodcnt[b] += goodcnt[a];
}

int n, m;
int u[500005], v[500005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) {
        int cnt;
        scanf("%d", &cnt);
        if (cnt == 1) {
            scanf("%d", u + i);
        } else {
            scanf("%d%d", u + i, v + i);
        }
    }
    vector<int> keep;
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            if (fin(u[i]) == fin(v[i])) continue;
            if (goodcnt[fin(u[i])] + goodcnt[fin(v[i])] > 1) continue;
        } else {
            if (goodcnt[fin(u[i])]) continue;
        }
        if (v[i]) {
            un(u[i], v[i]);
        } else {
            goodcnt[fin(u[i])]++;
        }
        keep.push_back(i);
    }
    int sub = 0;
    for (int i = 1; i <= m; i++) {
        if (uf[i] == i && goodcnt[i] == 0) sub++;
    }
    int ans = 1;
    for (int i = 1; i <= m - sub; i++) ans = mul(ans, 2);
    printf("%d %d\n", ans, (int)keep.size());
    for (int i = 0; i < keep.size(); i++) {
        printf("%d ", keep[i]);
    }
    return 0;
}