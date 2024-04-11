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

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    set<int> vals;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        vals.insert(a);
    }
    for (auto it = vals.begin(); it != vals.end(); it++) {
        if (vals.count(*it + k)) {
            printf("YES\n"); return;
        }
    }
    printf("NO\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}