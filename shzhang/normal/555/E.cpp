#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define ll long long
#define sz(x) ((int)((x).size()))

int n, m, q;

struct Edge {
    int to, cover, up, down;
};

vector<int> graph[200005];
vector<Edge> tree[200005];
bool vis1[200005];
int cover[200005], up[200005], down[200005];
int ancestor[200005][18];
int depth[200005];
int comp[200005];

bool ans = true;

int curcomp = 0;

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 17; i >= 0; i--) {
        if ((1 << i) & (depth[a] - depth[b]))
            a = ancestor[a][i];
    }
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) {
        if (ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

void dfs1(int node, int prt)
{
    vis1[node] = true; comp[node] = curcomp;
    for (int i = 0; i < sz(graph[node]); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        if (vis1[nxt]) {
            if (depth[node] > depth[nxt]) {
                cover[node]++; cover[nxt]--;
            } else {
                cover[node]--; cover[nxt]++;
            }
        } else {
            Edge e; e.to = nxt; e.cover = e.up = e.down = 0;
            tree[node].push_back(e);
            depth[nxt] = depth[node] + 1;
            ancestor[nxt][0] = node; dfs1(nxt, node);
        }
    }
}

void dfs2(int node, Edge& e, bool ignore)
{
    e.cover = cover[node];
    e.up = up[node];
    e.down = down[node];
    for (int i = 0; i < sz(tree[node]); i++) {
        Edge child = tree[node][i];
        dfs2(child.to, child, false);
        e.cover += child.cover; e.up += child.up; e.down += child.down;
    }
    //printf("%d %d %d %d\n", e.to, e.cover, e.up, e.down);
    if (!ignore && !e.cover && e.up && e.down) {
        printf("No"); exit(0);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (!vis1[i]) {
            roots.push_back(i); dfs1(i, 0); curcomp++;
        }
    }
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
    for (int i = 1; i <= q; i++) {
        int s, d; scanf("%d%d", &s, &d);
        if (comp[s] != comp[d]) {
            printf("No"); return 0;
        }
        int lcanode = lca(s, d);
        up[s]++; up[lcanode]--;
        down[d]++; down[lcanode]--;
    }
    for (int i = 0; i < sz(roots); i++) {
        Edge ignore; ignore.to = ignore.up = ignore.down = ignore.cover = 0;
        dfs2(roots[i], ignore, true);
    }
    printf("Yes"); return 0;
}