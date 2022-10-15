#include <cstdio>
#include <vector>

using namespace std;

vector<int> graph[200005];
vector<int> dfstree[200005];
vector<int> nontree[200005];

bool vis[200005];
int prt[200005];
int depth[200005];

int n, m;

int anscnt;
int ans[200005][4];

void addans(int a, int b, int c)
{
    anscnt++;
    ans[anscnt][1] = a; ans[anscnt][2] = b; ans[anscnt][3] = c;
}

void dfs1(int node, int parent)
{
    prt[node] = parent;
    vis[node] = true;
    depth[node] = depth[parent] + 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == parent) continue;
        if (vis[nxt]) {
            nontree[node].push_back(nxt);
        } else {
            dfstree[node].push_back(nxt);
            dfs1(nxt, node);
        }
    }
}

/* true -> node-parent edge taken */
bool dfs2(int node)
{
    vector<int> good_children;
    for (int i = 0; i < dfstree[node].size(); i++) {
        int child = dfstree[node][i];
        if (!dfs2(child)) good_children.push_back(child);
    }
    for (int i = 0; i < nontree[node].size(); i++) {
        if (depth[nontree[node][i]] > depth[node])
            good_children.push_back(nontree[node][i]);
    }
    for (int i = 0; i + 1 < good_children.size(); i += 2) {
        addans(good_children[i], node, good_children[i+1]);
    }
    if (good_children.size() % 2 && prt[node]) {
        addans(prt[node], node, good_children[good_children.size()-1]);
        return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i, 0); dfs2(i);
        }
    }
    printf("%d\n", anscnt);
    for (int i = 1; i <= anscnt; i++) {
        printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
    }
    return 0;
}