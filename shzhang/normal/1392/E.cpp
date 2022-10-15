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
ll a[30][30];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % 2 == 1) {
                printf("%lld ", 1LL << (i + j - 2));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
        fflush(stdout);
    }
    int q; scanf("%d", &q);
    for (int qry = 1; qry <= q; qry++) {
        ll k; scanf("%lld", &k);
        int currow = 1, curcol = 1;
        bool prevon = true;
        vector<pair<int, int> > ans;
        ans.push_back(make_pair(1, 1));
        for (ll i = 1; i <= n + n - 2; i++) {
            bool on = k & (1LL << i);
            if ((on && prevon) || (!on && !prevon)) {
                currow++;
            } else {
                curcol++;
            }
            prevon = on;
            ans.push_back(make_pair(currow, curcol));
        }
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
        fflush(stdout);
    }
    return 0;
}