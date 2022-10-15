#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstdint>
//
using namespace std;

int n, m;
vector<int> graph[500005];
vector<int> tgraph[500005];
int degree[500005];
int uf[500005];
int pre[500005];
int onenode[500005];
vector<int> onenode_conn[500005];
int dominated_by[500005];
int onelink[500005];
int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    uf[a] = b;
}

void answer(vector<int>& ans)
{
    printf("Yes\n%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void findpath(set<int>& path, int from, int to, bool indirect = false)
{
    queue<int> bfs;
    bfs.push(from);
    pre[from] = -1;
    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (degree[nxt] == 1 && nxt != to) continue;
            if (indirect && cur == from && nxt == to) continue;
            if (pre[nxt] == 0) {
                pre[nxt] = cur; bfs.push(nxt);
            }
        }
    }
    while (to != -1) {
        path.insert(to); to = pre[to];
    }
    for (int i = 1; i <= n; i++) pre[i] = 0;
}

void findpath_onenode(set<int>& path, int from, int onenodeid)
{
    queue<int> bfs;
    bfs.push(from);
    pre[from] = -1;
    int to = 0;
    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < tgraph[cur].size(); i++) {
            int nxt = tgraph[cur][i];
            if (pre[nxt] == 0) {
                pre[nxt] = cur; bfs.push(nxt);
            }
            if (onelink[nxt] == onenodeid && nxt != from) {
                to = nxt; goto loop_end;
            }
        }
    }
    loop_end:
    while (to != -1) {
        path.insert(to); to = pre[to];
    }
    for (int i = 1; i <= n; i++) pre[i] = 0;
}

void work(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++; degree[v]++;
    }
    if (n <= 2) {
        printf("No\n"); return;
    }
    //fprintf(stderr, "HERE");
    int node0 = -1; int hnodes = 0;
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        if (degree[i] >= 3) hnodes++;
        degree[i] %= 3;
        if (!degree[i]) node0 = i;
    }
    if (!hnodes) {
        printf("No\n"); return;
    }
    if (node0 != -1) {
        vector<int> ans;
        for (int i = 1; i <= n; i++) if (i != node0) ans.push_back(i);
        answer(ans); return;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 1) continue;
        for (int j = 0; j < graph[i].size(); j++) {
            if (degree[graph[i][j]] == 1) {
                vector<int> ans;
                for (int k = 1; k <= n; k++) if (k != i && k != graph[i][j]) ans.push_back(k);
                answer(ans); return;
            } else {
                onelink[graph[i][j]] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 2) continue;
        vector<int> nxt;
        for (int j = 0; j < graph[i].size(); j++) {
            if (degree[graph[i][j]] == 1) nxt.push_back(graph[i][j]);
            if (nxt.size() >= 2) break;
        }
        if (nxt.size() >= 2) {
            vector<int> ans;
            for (int k = 1; k <= n; k++) if (k != i && k != nxt[0] && k != nxt[1]) ans.push_back(k);
            answer(ans); return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 2) continue;
        for (int j = 0; j < graph[i].size(); j++) {
            if (degree[graph[i][j]] != 2) continue;
            if (i > graph[i][j]) continue;
            tgraph[i].push_back(graph[i][j]);
            tgraph[graph[i][j]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 2) continue;
        for (int j = 0; j < graph[i].size(); j++) {
            if (degree[graph[i][j]] != 2) continue;
            if (i > graph[i][j]) continue;
            if (fin(i) == fin(graph[i][j])) {
                set<int> path;
                findpath(path, i, graph[i][j], true);
                vector<int> ans;
                for (int k = 1; k <= n; k++) if (!path.count(k)) ans.push_back(k);
                answer(ans); return;
            }
            un(i, graph[i][j]);
            //tgraph[i].push_back(graph[i][j]);
            //tgraph[graph[i][j]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] != 1) continue;
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j];
            if (onenode[fin(nxt)] && onenode[fin(nxt)] != i) {
                set<int> path;
                findpath(path, i, onenode[fin(nxt)]);
                vector<int> ans;
                for (int k = 1; k <= n; k++) if (!path.count(k)) ans.push_back(k);
                answer(ans); return;
            } else {
                onenode[fin(nxt)] = i;
                onenode_conn[fin(nxt)].push_back(nxt);
            }
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", uf[i]);
    for (int i = 1; i <= n; i++) {
        /* i is tree representative */
        if (!onenode[i]) continue;
        //printf("work %d\n", i);
        if (dominated_by[onenode[i]]) {
            set<int> keep_set;
            findpath_onenode(keep_set, onenode_conn[dominated_by[onenode[i]]][0], onenode[i]);
            findpath_onenode(keep_set, onenode_conn[i][0], onenode[i]);
            keep_set.insert(onenode[i]);
            vector<int> ans;
            for (int k = 1; k <= n; k++) if (!keep_set.count(k)) ans.push_back(k);
            if (ans.empty()) {
                printf("No\n");
            } else {
                answer(ans);
            }
            return;
        }
        dominated_by[onenode[i]] = i;
    }
    printf("No\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int data = 1; data <= T; data++) {
        work();
        for (int i = 1; i <= n; i++) graph[i].clear(), tgraph[i].clear(),
            degree[i] = 0, onenode[i] = 0, onenode_conn[i].clear(),
            dominated_by[i] = 0, onelink[i] = 0;
    }
    return 0;
}