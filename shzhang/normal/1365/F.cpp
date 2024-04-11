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

void work(void)
{
    /* solve problem here */
    int n;
    scanf("%d", &n);
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); a.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); b.push_back(x);
    }
    if (n % 2 && a[n / 2] != b[n / 2]) {
        printf("No\n"); return;
    }
    int l = 0; int r = n - 1;
    vector<pair<int, int> > pr1, pr2;
    while (l < r) {
        int x = a[l]; int y = a[r];
        if (x > y) swap(x, y);
        pr1.push_back(make_pair(x, y));
        x = b[l]; y = b[r];
        if (x > y) swap(x, y);
        pr2.push_back(make_pair(x, y));
        l++; r--;
    }
    sort(pr1.begin(), pr1.end());
    sort(pr2.begin(), pr2.end());
    for (int i = 0; i < pr1.size(); i++) {
        if (pr1[i].first != pr2[i].first ||
            pr1[i].second != pr2[i].second) {
                printf("No\n"); return;
            }
    }
    printf("Yes\n");
    /* remember to clean up any global variables if needed */
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}