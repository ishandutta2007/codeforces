#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

vector<int> graph[100005];
vector<int> tree[100005];
vector<int> upedge[100005];
bool vis[100005];
int depth[100005];
int prt[100005];
bool block[100005];

int sqr = 0;

int n, m;

vector<int> indset;

void dfs1(int node, int parent)
{
    depth[node] = depth[parent] + 1;
    vis[node] = true;
    prt[node] = parent;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!vis[nxt]) {
            dfs1(nxt, node);
            tree[node].push_back(nxt);
        } else if (depth[nxt] > depth[node]) {
            if (depth[nxt] - depth[node] >= sqr - 1) {
                printf("2\n%d\n", depth[nxt] - depth[node] + 1);
                while (1) {
                    printf("%d ", nxt);
                    if (nxt == node) break;
                    nxt = prt[nxt];
                }
                exit(0);
            }
            upedge[nxt].push_back(node);
        }
    }
}

void dfs2(int node)
{
    for (int i = 0; i < tree[node].size(); i++) {
        dfs2(tree[node][i]);
    }
    if (!block[node]) {
        indset.push_back(node);
        for (int i = 0; i < upedge[node].size(); i++) {
            block[upedge[node][i]] = true;
        }
        block[prt[node]] = true;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 1000; i++) {
        if (i * i == n) {
            sqr = i;
        } else if (i * i < n) {
            sqr = i + 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1);
    printf("1\n");
    for (int i = 0; i < sqr; i++) {
        printf("%d ", indset[i]);
    }
    return 0;
}