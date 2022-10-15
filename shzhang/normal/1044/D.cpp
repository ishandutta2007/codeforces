#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
//
using namespace std;

int q;

map<int, int> ids;
int nextid = 1;

int uf[400005];
int siz[400005];

struct Edge {
    int to, wt;
};

Edge mkedge(int to, int wt)
{
    Edge e; e.to = to; e.wt = wt; return e;
}

vector<Edge> graph[400005];
int xorval[400005];

void dfs(int node, int prt, int xorv)
{
    xorval[node] = xorv;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i].to != prt)
            dfs(graph[node][i].to, node, xorv ^ graph[node][i].wt);
    }
}

int find(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

void un(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    siz[a] += siz[b];
    uf[b] = a;
}

int main()
{
    scanf("%d", &q);
    for (int i = 1; i <= 400004; i++) uf[i] = i;
    for (int i = 1; i <= 400004; i++) siz[i] = 1;
    int last = 0;
    for (int query = 1; query <= q; query++) {
        int T, l, r, x;
        scanf("%d%d%d", &T, &l, &r);
        l ^= last; r ^= last;
        if (l > r) {
            int t = l; l = r; r = t;
        }
        l--;
        if (T == 1) {
            scanf("%d", &x); x ^= last;
            //printf("%d %d %d %d\n", T, l, r, x);
            if (!ids.count(l)) ids[l] = nextid++;
            if (!ids.count(r)) ids[r] = nextid++;
            l = ids[l]; r = ids[r];
            if (find(l) == find(r)) continue;
            if (siz[find(l)] > siz[find(r)]) {
                int t = l; l = r; r = t;
            }
            dfs(l, r, xorval[r] ^ x);
            graph[l].push_back(mkedge(r, x));
            graph[r].push_back(mkedge(l, x));
            un(l, r);
        } else {
            //printf("%d %d %d\n", T, l, r);
            if ((!ids.count(l)) || (!ids.count(r))) {
                last = 1; printf("-1\n"); continue;
            }
            l = ids[l]; r = ids[r];
            if (find(l) != find(r)) {
                last = 1; printf("-1\n"); continue;
            }
            printf("%d\n", xorval[l] ^ xorval[r]);
            last = xorval[l] ^ xorval[r];
        }
    }
    return 0;
}