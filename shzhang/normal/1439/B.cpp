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
#include <unordered_set>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

unordered_set<int> graph[100005];
bool deleted[100005];

int n, m, k;

queue<int> to_remove;

void delnode(int node)
{
    for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
        graph[*i].erase(node);
        if (graph[*i].size() == k - 1) to_remove.push(*i);
    }
    graph[node].clear();
    deleted[node] = true;
}

void work(void)
{
    scanf("%d%d%d", &n, &m, &k);
    bool can_clique = ((ll)(k) * (ll)(k-1)) / 2LL <= m;
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() < k) to_remove.push(i);
    }
    while (!to_remove.empty()) {
        int node = to_remove.front(); to_remove.pop();
        if (graph[node].size() == k - 1 && can_clique) {
            bool has_clique = true;
            int* seq = new int[k];
            int idx = 0;
            for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
                seq[idx] = *i; idx++;
            }
            for (int i = 0; i < k - 1; i++) {
                for (int j = i + 1; j < k - 1; j++) {
                    if (!(graph[seq[i]].count(seq[j]))) {
                        has_clique = false; goto loop_end;
                    }
                }
            }
            loop_end:
            if (has_clique) {
                printf("2\n");
                printf("%d ", node);
                for (int i = 0; i < k - 1; i++) {
                    printf("%d ", seq[i]);
                }
                printf("\n");
                delete[] seq; goto cleanup;
            }
            delete[] seq;
        }
        delnode(node);
    }
    for (int i = 1; i <= n; i++) {
        if (!deleted[i]) ans.push_back(i);
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        printf("1 %d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        printf("\n");
    }
    cleanup:
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        deleted[i] = false;
    }
    while (!to_remove.empty()) to_remove.pop();
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}