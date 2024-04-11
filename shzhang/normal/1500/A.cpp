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
pair<int, int> a[200005];
vector<int> diffpos[2500005];
vector<pair<int, int> > prpos[5000005];

static inline bool distinct(pair<int, int> x, pair<int, int> y)
{
    return x.first != y.first && x.first != y.second && x.second != y.first && x.second != y.second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a[i].first = x; a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) {
        //printf("%d %d", a[i].first - a[i-1].first, i);
        diffpos[a[i].first - a[i-1].first].push_back(i);
    }
    for (int i = 0; i <= 2500000; i++) {
        if (diffpos[i].size() <= 2) continue;
        sort(diffpos[i].begin(), diffpos[i].end());
        int p1 = diffpos[i][0], p2 = diffpos[i][diffpos[i].size() - 1];
        printf("YES\n%d %d %d %d", a[p1-1].second, a[p2].second, a[p1].second, a[p2 - 1].second);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            prpos[a[i].first + a[j].first].push_back(make_pair(i, j));
        }
    }
    for (int i = 1; i <= 5000000; i++) {
        if (prpos[i].size() < 2) continue;
        for (int j = 0; j < prpos[i].size(); j++) {
            if (distinct(prpos[i][j], prpos[i][0])) {
                printf("YES\n%d %d %d %d\n", a[prpos[i][j].first].second, a[prpos[i][j].second].second,
                a[prpos[i][0].first].second, a[prpos[i][0].second].second);
                return 0;
            }
            if (distinct(prpos[i][j], prpos[i][1])) {
                printf("YES\n%d %d %d %d\n", a[prpos[i][j].first].second, a[prpos[i][j].second].second,
                a[prpos[i][1].first].second, a[prpos[i][1].second].second);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}