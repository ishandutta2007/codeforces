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

int a[250005];

int n;

int solve()
{
    int l = min(a[1], a[2]);
    int r = max(a[1], a[2]);
    bool curleft = (a[2] < a[1]);
    //int lastpos = 2;
    int ans = 1;
    for (int i = 3; i <= n; i++) {
        if (curleft) {
            if (a[i] < l) {
                l = a[i]; //lastpos = i;
            } else if (a[i] > r) {
                r = a[i]; //lastpos = i;
                ans++; curleft = false;
            }
        } else {
            if (a[i] < l) {
                l = a[i]; //lastpos = i;
                ans++; curleft = true;
            } else if (a[i] > r) {
                r = a[i]; //lastpos = i;
            }
        }
    }
    return ans;
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    if (n == 1) {
        printf("0\n");
    } else if (n == 2) {
        printf("1\n");
    } else {
        int ans1 = solve();
        reverse(a + 1, a + n + 1);
        int ans2 = solve();
        printf("%d\n", ans1 + ans2 - 1);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}