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

int n, m;
vector<int> graph[500005];
int t[500005];
int seq[500005];

bool cmp(int a, int b)
{
    return t[a] < t[b];
}

int cover[500005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", t + i); seq[i] = i;
    }
    sort(seq + 1, seq + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int node = seq[i];
        if (cover[node] != t[node] - 1) {
            printf("-1"); return 0;
        }
        for (int j = 0; j < graph[node].size(); j++) {
            if (cover[graph[node][j]] == t[node] - 1)
                cover[graph[node][j]] = t[node];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", seq[i]);
    return 0;
}