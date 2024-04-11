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

int p[205];
int pinv[205];
int cycle[205];

int tmp[205];
int nxt[205];
int ans[205];

int uf[205];

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


void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i); cycle[i] = 0;
        pinv[p[i]] = i;
    }
    int cycid = 1;
    for (int i = 1; i <= n; i++) {
        if (!cycle[i]) {
            int cur = i;
            while (!cycle[cur]) {
                cycle[cur] = cycid;
                cur = p[cur];
            }
            cycid++;
        }
    }
    for (int i = 1; i < cycid; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) tmp[i] = i;
    for (int i = 2; i <= n; i++) {
        if (fin(cycle[i]) != fin(cycle[i-1])) {
            swap(tmp[i], tmp[i-1]);
            un(cycle[i], cycle[i-1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        nxt[i] = pinv[tmp[i]];
    }
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        printf("%d ", cur);
        cur = nxt[cur];
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}