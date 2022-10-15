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

int a[100005];

void work(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n || (a[i] > max(a[i-1], a[i+1])
            || (a[i] < min(a[i-1], a[i+1])))) ans.push_back(a[i]);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}