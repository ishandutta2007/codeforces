#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

vector<int> graph[100005];
vector<int> tree[100005];
int wt[100005];
bool vis[100005];
int depth[100005];

int n, m;

vector<pair<int, int> > ans;

void dfs1(int node, int parent)
{
    depth[node] = depth[parent] + 1;
    vis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!vis[nxt]) {
            dfs1(nxt, node);
            tree[node].push_back(nxt);
        } else if (depth[nxt] > depth[node]) {
            wt[nxt]++;
            wt[node]--;
            ans.push_back(make_pair(nxt, node));
        }
    }
}

void dfs2(int node)
{
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        dfs2(child);
        if (wt[child] == 0) {
            printf("0"); exit(0);
        }
        wt[node] += wt[child];
        ans.push_back(make_pair(node, child));
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}