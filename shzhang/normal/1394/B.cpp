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

int n, m, k;

struct Edge {
    int to;
    int wt;
};

struct RevEdge {
    int from;
    int id;
};

bool operator<(Edge a, Edge b)
{
    return a.wt < b.wt;
}

vector<Edge> graph[200005];
vector<RevEdge> revgraph[200005];
vector<int> nodes[15];
bool flag[200005];

bool exclude[15][15][15][15];
int ans[15];
int final_ans = 0;

void search(int idx)
{
    if (idx == k + 1) {
        //for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
        //printf("\n");
        final_ans++; return;
    }
    for (int i = 1; i <= idx; i++) {
        ans[idx] = i;
        bool good = true;
        for (int j = 1; j <= idx; j++) {
            if (exclude[j][ans[j]][idx][ans[idx]]) good = false;
        }
        if (good) search(idx+1);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        Edge e; e.to = v; e.wt = w;
        graph[u].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            RevEdge r; r.from = i; r.id = j;
            revgraph[graph[i][j].to].push_back(r);
        }
        nodes[graph[i].size()].push_back(i);
    }
    for (int x = 1; x <= k; x++) {
        for (int y = 1; y <= x; y++) {
            for (int i = 1; i <= n; i++) flag[i] = false;
            for (int idx = 0; idx < nodes[x].size(); idx++) {
                int i = nodes[x][idx];
                if (flag[graph[i][y - 1].to]) exclude[x][y][x][y] = true;
                flag[graph[i][y - 1].to] = true;
            }
            for (int i = 1; i <= n; i++) {
                if (!flag[i]) continue;
                for (int j = 0; j < revgraph[i].size(); j++) {
                    RevEdge re = revgraph[i][j];
                    //printf("%d %d %d %d\n", x, y, (int)graph[re.from].size(), re.id+1);
                    if (x == graph[re.from].size() && y == re.id + 1) continue;
                    exclude[x][y][graph[re.from].size()][re.id + 1] = true;
                }
            }
        }
    }
    search(1);
    printf("%d", final_ans);
    return 0;
}