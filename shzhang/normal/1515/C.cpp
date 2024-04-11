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

int ans[100005];

void work()
{
    int n, m, x; scanf("%d%d%d", &n, &m, &x);
    priority_queue<pair<int, int> > pq;
    for (int i = 1; i <= m; i++) {
        pq.push(make_pair(0, i));
    }
    for (int i = 1; i <= n; i++) {
        int h; scanf("%d", &h);
        pair<int, int> top = pq.top(); pq.pop();
        ans[i] = top.second;
        pq.push(make_pair(top.first - h, top.second));
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}