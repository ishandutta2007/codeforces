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

vector<int> pos[300005];
int maxgap[300005];
int ans[300005];
int n;

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n; i++) maxgap[i] = 0;
    for (int i = 1; i <= n; i++) ans[i] = -1;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        pos[a].push_back(i);
    }
    int first_exist = n + 1;
    for (int i = n; i >= 1; i--) {
        if (pos[i].empty()) continue;
        maxgap[i] = pos[i][0];
        for (int j = 1; j < pos[i].size(); j++) {
            maxgap[i] = max(maxgap[i], pos[i][j] - pos[i][j-1]);
        }
        maxgap[i] = max(maxgap[i], n + 1 - pos[i][pos[i].size() - 1]);
        //printf("%d ", maxgap[i]);
        ans[maxgap[i]] = i;
        first_exist = min(first_exist, maxgap[i]);
    }
    for (int i = first_exist; i <= n; i++) {
        if (ans[i] == -1 || (ans[i] > ans[i-1] && i != first_exist)) ans[i] = ans[i-1];
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}