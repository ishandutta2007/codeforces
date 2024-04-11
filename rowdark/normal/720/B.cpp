#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
const int N = 10000;
const int M = N << 1;
int head[N], to[M << 1], next[M << 1], color[M], depth[N], low[N], c, limit[M];
bool visited[M];
std::vector<int> stack;
std::vector<int> graph[M];
std::set<int> match[M];
void dfs(int u)
{
    low[u] = depth[u];
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        if (visited[iterator >> 1]) {
            continue;
        }
        visited[iterator >> 1] = true;
        auto&& v = to[iterator];
        stack.push_back(iterator >> 1);
        if (depth[v] == -1) {
            depth[v] = depth[u] + 1;
            dfs(v);
            if (depth[u] < low[v]) {
                int last = stack.back();
                stack.pop_back();
                limit[c] = 1;
                graph[color[last]].push_back(c ++);
            } else if (depth[u] == low[v]) {
                int last = limit[c] = -1;
                while (last != (iterator >> 1)) {
                    last = stack.back();
                    stack.pop_back();
                    limit[c] ++;
                    graph[color[last]].push_back(c);
                }
                c ++;
            }
            low[u] = std::min(low[u], low[v]);
        } else {
            low[u] = std::min(low[u], depth[v]);
        }
    }
}
bool find(int u)
{
    for (auto&& v : graph[u]) {
        if ((int)match[v].size() < limit[v]) {
            match[v].insert(u);
            return true;
        }
    }
    for (auto&& v : graph[u]) if(!visited[v]) {
        visited[v] = true;
        for (auto&& uu : match[v]) {
            if (find(uu)) {
                match[v].erase(uu);
                match[v].insert(u);
                return true;
            }
        }
    }
    return false;
}
int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < m << 1; ++ i) {
            scanf("%d", to + i);
            to[i] --;
            if (i & 1) {
                scanf("%d", color + (i >> 1));
                color[i >> 1] --;
            }
        }
        memset(head, -1, sizeof(*head) * n);
        for (int i = 0; i < m << 1; ++ i) {
            auto& h = head[to[i ^ 1]];
            next[i] = h;
            h = i;
        }
        memset(depth, -1, sizeof(*depth) * n);
        memset(visited, 0, sizeof(*visited) * m);
        depth[0] = 0;
        c = 0;
        for (int i = 0; i < m; ++ i) {
            graph[i].clear();
        }
        dfs(0);
        for (int i = 0; i < c; ++ i) {
            match[i].clear();
        }
        int result = 0;
        memset(visited, 0, sizeof(*visited) * c);
        for (int u = 0; u < m; ++ u) {
            if (find(u)) {
                result ++;
                memset(visited, 0, sizeof(*visited) * c);
            }
        }
        printf("%d\n", result);
    }
}