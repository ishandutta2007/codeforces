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

#define sq(x) ((double)(x) * (double)(x))

int x[100005];
int y[100005];

int xcnt, ycnt;

void work()
{
    xcnt = ycnt = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if (a == 0) {
            ycnt++; y[ycnt] = b;
        } else {
            xcnt++; x[xcnt] = a;
        }
    }
    vector<double> a, b;
    for (int i = 1; i <= n; i++) {
        a.push_back(sq(x[i]));
        b.push_back(sq(y[i]));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans += sqrt(a[i] + b[i]);
    }
    printf("%.10f\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}