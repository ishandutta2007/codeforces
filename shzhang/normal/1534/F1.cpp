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

#define encode(x, y) (((x)-1) * m + (y))

char* grid[400005];
bool* up[400005];
bool* left[400005];
bool* right[400005];
int n, m;
char s[400005];

vector<int> graph[400005];

bool flag[400005];
bool vis[400005];
int indeg[400005];
bool onstack[400005];
int minid[400005];
int stk[400005];
int idx[400005];
int stktop = 0;
int nextidx = 1;
int nextscc = 1;
int scc[400005];
int represent[400005];

void tarjan(int node)
{
    onstack[node] = true;
    minid[node] = nextidx;
    stk[stktop] = node; stktop++;
    idx[node] = nextidx; nextidx++;
    for (int i = 0; i < graph[node].size(); i++) {
        int other = graph[node][i];
        if (!idx[other]) {
            tarjan(other);
            minid[node] = min(minid[node], minid[other]);
        } else if (onstack[other]) {
            minid[node] = min(minid[node], idx[other]);
        }
    }
    if (minid[node] == idx[node]) {
        while (1) {
            stktop--; scc[stk[stktop]] = nextscc;
            /*if (open[(stk[stktop] - 1) / d + 1][(stk[stktop] - 1) % d + 1])
                museums.push_back((stk[stktop] - 1) / d + 1);*/
            onstack[stk[stktop]] = false;
            if (stk[stktop] == node) break;
        }
        //sort(museums.begin(), museums.end());
        //for (int i = 0; i < museums.size(); i++) {
        //    if (i == 0 || museums[i] != museums[i-1]) museumcnt[nextscc]++;
        //}
        //museums.clear();
        represent[nextscc] = node;
        nextscc++;
    }
}


int main()
{
    scanf("%d%d", &n, &m);
    //for (int i = 1; i <= n * m; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) {
        grid[i] = new char[m + 5];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1 && grid[i-1][j] == '#') {
                graph[encode(i, j)].push_back(encode(i-1, j));
            }
            if (j > 1 && grid[i][j-1] == '#') {
                graph[encode(i, j)].push_back(encode(i, j-1));
            }
            if (j < m && grid[i][j+1] == '#') {
                graph[encode(i, j)].push_back(encode(i, j+1));
            }
            if (i < n) {
                graph[encode(i, j)].push_back(encode(i+1, j));
            }
        }
    }
    for (int i = 1; i <= n * m; i++) {
        if (!idx[i]) {
            tarjan(i);
        }
    }
    /*for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            printf("%d ", scc[encode(x, y)]);
        }
        printf("\n");
    }*/
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#') {
                que.push(encode(i, j));
            }
        }
    }
    while (!que.empty()) {
        int node = que.front(); que.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            que.push(nxt);
        }
    }
    /*for (int i = 1; i <= n * m; i++) {
        if (vis[i]) printf("%d\n", i);
    }*/
    for (int i = 1; i <= n * m; i++) {
        if (!vis[i]) continue;
        for (int j = 0; j < graph[i].size(); j++) {
            if (scc[graph[i][j]] != scc[i])
                indeg[scc[graph[i][j]]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i < nextscc; i++) {
        if (vis[represent[i]] && !indeg[i]) {
            ans++;// printf("%d\n", i);
        }
    }
    printf("%d", ans);
    return 0;
}