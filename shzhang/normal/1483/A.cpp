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

vector<int> seq[100005];
int cnt[100005];
int ans[100005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    int upval = (m / 2) + (m % 2);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= m; i++) seq[i].clear();
    for (int i = 1; i <= m; i++) {
        int k; scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int val; scanf("%d", &val); seq[i].push_back(val);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (seq[i].size() == 1) {
            cnt[seq[i][0]]++; ans[i] = seq[i][0];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > upval) {
            printf("NO\n"); return;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (seq[i].size() == 1) continue;
        int mincnt = 10000000, fr = 0;
        for (int j = 0; j < seq[i].size(); j++) {
            if (cnt[seq[i][j]] < mincnt) {
                mincnt = cnt[seq[i][j]];
                fr = seq[i][j];
            }
        }
        cnt[fr]++;
        ans[i] = fr;
    }
    printf("YES\n");
    for (int i = 1; i <= m; i++) {
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