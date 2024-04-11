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
int a[200005];
vector<int> in[200005];
int b[200005];

int uf[200005];

int fin(int x)
{
    if (uf[x] == x) return x;
    return uf[x] = fin(uf[x]);
}

void un(int x, int y)
{
    x = fin(x); y = fin(y);
    if (x == y) return;
    uf[x] = y;
}

bool oncycle[200005];
bool tmp[200005];

void markcycle(int from, int to)
{
    while (true) {
        oncycle[from] = true;
        if (from == to) break;
        from = a[from];
    }
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        uf[i] = i; oncycle[i] = false;
        in[i].clear(); b[i] = 0; tmp[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        in[a[i]].push_back(i);
        if (fin(i) == fin(a[i])) {
            markcycle(a[i], i);
        } else {
            un(i, a[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i].empty()) continue;
        int cur = in[i][0];
        for (int j = 1; j < in[i].size(); j++) {
            if (!oncycle[in[i][j]]) cur = in[i][j];
        }
        b[cur] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i]) tmp[b[i]] = true;
    }
    vector<pair<int, int> > chains;
    for (int i = 1; i <= n; i++) {
        if (tmp[i]) continue;
        int nxt = i;
        while (b[nxt]) nxt = b[nxt];
        chains.push_back(make_pair(i, nxt));
    }
    for (int i = 0; i + 1 < chains.size(); i++) {
        b[chains[i].second] = chains[i+1].first;
    }
    if (!chains.empty()) {
        b[chains.back().second] = chains[0].first;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == a[i]) ans++;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}