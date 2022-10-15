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
int cnt[200005];
vector<int> graph[200005];

void work()
{
    scanf("%d", &n);
    priority_queue<int> a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", cnt + i);
        if (!cnt[i]) a.push(-i);
        for (int j = 0; j < cnt[i]; j++) {
            int x; scanf("%d", &x);
            graph[x].push_back(i);
        }
    }
    int remain = n;
    int ans = 1;
    while (remain) {
        if (a.empty()) {
            swap(a, b); ans++;
            if (a.empty()) {
                ans = -1; break;
            }
        }
        int cur = a.top(); a.pop();
        cur = -cur;
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            cnt[nxt]--;
            if (cnt[nxt] == 0) {
                if (nxt > cur) {
                    a.push(-nxt);
                } else {
                    b.push(-nxt);
                }
            }
        }
        remain--;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0; graph[i].clear();
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}