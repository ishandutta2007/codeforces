#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long
#define updiv(a, b) ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1)
//
struct Event {
    int city, virus, t;
};

int n;

vector<int> graph[200005];
int ancestor[200005][18];
int depth[200005];
int dfsorder[200005];
int virustype[200005];
int starttime = 1;

bool operator<(Event a, Event b)
{
    return a.t > b.t || (a.t == b.t && a.virus > b.virus);
}

bool nodecmp(int a, int b)
{
    return dfsorder[a] < dfsorder[b];
}

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    dfsorder[node] = starttime++;
    ancestor[node][0] = prt;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (child == prt) continue;
        dfs(child, node);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) {
        int t = a; a = b; b = t;
    }
    for (int i = 0; i < 18; i++) {
        if ((depth[a] - depth[b]) & (1 << i)) {
            a = ancestor[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 17; i >= 0; i--) {
        if (ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i]; b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}
int origin[200005];
int speed[200005];
int stk[200005];
int stkcur = 0;
vector<int> vtree[200005];

void work(void)
{
    int k, m;
    scanf("%d%d", &k, &m);
    vector<int> vtree_nodes;
    vector<int> important;
    priority_queue<Event> events;
    for (int i = 1; i <= k; i++) {
        int v, s; scanf("%d%d", &v, &s);
        origin[i] = v; speed[i] = s;
        Event e; e.city = v; e.virus = i; e.t = 0;
        events.push(e);
        vtree_nodes.push_back(v);
    }
    for (int i = 1; i <= m; i++) {
        int u; scanf("%d", &u);
        important.push_back(u); vtree_nodes.push_back(u);
    }
    sort(vtree_nodes.begin(), vtree_nodes.end(), nodecmp);
    stkcur = 0; stk[stkcur] = 1;
    set<int> in_vtree; in_vtree.insert(1);
    for (int i = 0; i < vtree_nodes.size(); i++) {
        int node = vtree_nodes[i];
        //printf("work %d\n", node);
        if (node == 1) continue;
        if (i && node == vtree_nodes[i-1]) continue;
        in_vtree.insert(node);
        int lcanode = lca(node, stk[stkcur]);
        if (lcanode == stk[stkcur]) {
            //printf("add to stack\n");
            stk[++stkcur] = node;
        } else {
            if (in_vtree.count(lcanode)) {
                while (depth[stk[stkcur]] > depth[lcanode]) {
                    //printf("link %d %d\n", stk[stkcur - 1], stk[stkcur]);
                    vtree[stk[stkcur - 1]].push_back(stk[stkcur]);
                    vtree[stk[stkcur]].push_back(stk[stkcur - 1]);
                    stkcur--;
                }
            } else {
                while (depth[stk[stkcur]] > depth[lcanode]) {
                    if (depth[stk[stkcur - 1]] > depth[lcanode]) {
                        //printf("link %d %d\n", stk[stkcur - 1], stk[stkcur]);
                        vtree[stk[stkcur - 1]].push_back(stk[stkcur]);
                        vtree[stk[stkcur]].push_back(stk[stkcur - 1]);
                    } else {
                        //printf("link %d %d\n", lcanode, stk[stkcur]);
                        vtree[lcanode].push_back(stk[stkcur]);
                        vtree[stk[stkcur]].push_back(lcanode);
                    }
                    stkcur--;
                }
                stk[++stkcur] = lcanode;
                in_vtree.insert(lcanode);
            }
            stk[++stkcur] = node;
        }
    }
    //printf("\n");
    while (stkcur) {
        //printf("link %d %d\n", stk[stkcur - 1], stk[stkcur]);
        vtree[stk[stkcur - 1]].push_back(stk[stkcur]);
        vtree[stk[stkcur]].push_back(stk[stkcur - 1]);
        stkcur--;
    }
    while (!events.empty()) {
        Event e = events.top(); events.pop();
        if (virustype[e.city]) continue;
        //printf("%d infected with %d\n", e.city, e.virus);
        virustype[e.city] = e.virus;
        for (int i = 0; i < vtree[e.city].size(); i++) {
            Event newe; newe.city = vtree[e.city][i];
            if (virustype[newe.city]) continue;
            newe.virus = e.virus;
            newe.t = updiv(depth[origin[e.virus]] + depth[newe.city]
                - 2 * depth[lca(origin[e.virus], newe.city)], speed[e.virus]);
            events.push(newe);
        }
    }
    for (int i = 0; i < important.size(); i++) {
        printf("%d ", virustype[important[i]]);
    }
    printf("\n");
    for (auto it = in_vtree.begin(); it != in_vtree.end(); it++) {
        int node = *it; vtree[node].clear(); virustype[node] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        work();
    }
    return 0;
}