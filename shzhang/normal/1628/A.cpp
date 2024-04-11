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
int f[200005];
int remain[200005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 0; i <= n + 2; i++) f[i] = remain[i] = 0;
    for (int i = 1; i <= n; i++) remain[a[i]]++;
    int cur = 1;
    vector<int> ans;
    while (cur <= n) {
        int last = n;
        int mex = 0;
        for (int i = cur; i <= n; i++) {
            f[a[i]]++;
            while (f[mex]) mex++;
            remain[a[i]]--;
            if (i == n || !remain[mex]) {
                last = i; break;
            }
        }
        for (int i = cur; i <= last; i++) f[a[i]] = 0;
        ans.push_back(mex);
        cur = last + 1;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
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