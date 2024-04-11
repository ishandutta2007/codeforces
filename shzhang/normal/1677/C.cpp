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

int ca[100005];
int cb[100005];
vector<int> graph[100005];
bool vis[100005];

int dfs(int node)
{
    if (vis[node]) return 0;
    vis[node] = true;
    int ans = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        ans += dfs(nxt);
    }
    return ans;
}

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        vis[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", ca + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", cb + i);
    }
    for (int i = 1; i <= n; i++) {
        graph[ca[i]].push_back(cb[i]);
        graph[cb[i]].push_back(ca[i]);
    }
    vector<int> diffs;
    for (int i = 1; i <= n; i++) {
        int cnt = dfs(i);
        if (cnt == 0) continue;
        for (int j = 1; j <= cnt / 2; j++) diffs.push_back(2);
        if (cnt % 2) diffs.push_back(0);
        for (int j = 1; j <= cnt / 2; j++) diffs.push_back(-2);
    }
    sort(diffs.begin(), diffs.end());
    reverse(diffs.begin(), diffs.end());
    ll ans = 0, cur = 0;
    for (int i = 0; i < diffs.size(); i++) {
        cur += (ll)diffs[i];
        ans += cur;
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}