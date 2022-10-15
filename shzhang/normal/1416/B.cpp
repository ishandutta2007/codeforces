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
int a[10005];

struct Op {
    int i, j, x;
};

vector<Op> ops;

void do_op(int i, int j, int x)
{
    Op o; o.i = i; o.j = j; o.x = x;
    ops.push_back(o);
    a[i] -= x * i;
    a[j] += x * i;
}

void work()
{
    ops.clear();
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); tot += a[i];
    }
    if (tot % n) {
        printf("-1\n"); return;
    }
    int goal = tot / n;
    for (int i = 2; i <= n; i++) {
        int need = i - (a[i] % i);
        if (need == i) need = 0;
        do_op(1, i, need);
        do_op(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; i++) {
        do_op(1, i, goal);
    }
    printf("%d\n", (int)ops.size());
    for (int i = 0; i < ops.size(); i++) {
        printf("%d %d %d\n", ops[i].i, ops[i].j, ops[i].x);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}