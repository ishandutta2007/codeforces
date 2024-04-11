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

vector<int> graph[300005];
bool vis[300005];
bool teacher[300005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> que; que.push(1); vis[1] = true;
    int remain = n;
    vector<int> teacher_pos;
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        bool has_t = false;
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (!vis[nxt]) continue;
            if (teacher[nxt]) has_t = true;
        }
        if (!has_t) {
            teacher[cur] = true; teacher_pos.push_back(cur);
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (!vis[nxt]) {
                vis[nxt] = true;
                que.push(nxt);
            }
        }
        remain--;
    }
    if (remain) {
        printf("NO\n");
    } else {
        printf("YES\n%d\n", (int)teacher_pos.size());
        for (int i = 0; i < teacher_pos.size(); i++) {
            printf("%d ", teacher_pos[i]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        graph[i].clear(); vis[i] = false; teacher[i] = false;
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}