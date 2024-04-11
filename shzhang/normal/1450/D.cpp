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

int a[300005];
vector<int> pos[300005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[a[i]].push_back(i);
    }
    if (pos[1].empty()) {
        for (int i = 1; i <= n; i++) printf("0");
        printf("\n");
        return;
    }
    int pval = -1;
    set<int> good;
    int minpos = 1000000, maxpos = 0;
    int curtot = 0;
    bool hasgap = false; bool hasdouble = false;
    for (int i = n; i >= 1; i--) {
        if (pos[i].empty()) continue;
        curtot += pos[i].size();
        // BE CAREFUL ABOUT CLEAR, particularly 1
        if (pval != -1 && pval - i != 1) {
            //printf("here");
            good.clear(); good.insert(curtot); hasgap = true;
        } else if (pos[i].size() >= 2) {
            good.clear(); good.insert(curtot); hasdouble = true;
        } else if (pos[i][0] < minpos || pos[i][0] > maxpos) {
            good.insert(curtot);
        } else {
            bool has1 = false;
            if (good.count(1)) has1 = true;
            good.clear();
            good.insert(curtot);
            if (has1) good.insert(1);
        }
        for (int j = 0; j < pos[i].size(); j++) {
            minpos = min(minpos, pos[i][j]);
            maxpos = max(maxpos, pos[i][j]);
        }
        pval = i;
        /*for (int j = 1; j <= curtot; j++) {
            printf("%d", (int)good.count(j));
        }
        printf("\n");*/
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", (int)good.count(i));
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}