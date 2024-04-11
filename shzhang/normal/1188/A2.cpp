#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
    int to, val;
};

struct Operation {
    int u, v, x;
};

vector<Edge> graph[1005];
vector<int> leaves[1005];
vector<Operation> ops;
int n;

int findleaf(int cur, int pre)
{
    while (graph[cur].size() > 1) {
        for (int i = 0; i < graph[cur].size(); i++) {
            if (graph[cur][i].to != pre) {
                pre = cur; cur = graph[cur][i].to; break;
            }
        }
    }
    return cur;
}

Operation make_op(int u, int v, int x)
{
    Operation op; op.u = u; op.v = v; op.x = x;
    return op;
}

void dfs(int node, int parent)
{
    if (graph[node].size() == 1) {
        leaves[node].push_back(node);
        return;
    }
    if (graph[node].size() == 2) {
        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][i].to;
            if (child != parent) {
                dfs(child, node);
                for (int x = 0; x < leaves[child].size(); x++) {
                    leaves[node].push_back(leaves[child][x]);
                }
            }
        }
    } else {
        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][i].to;
            int edgewt = graph[node][i].val;
            int otherleaf = findleaf(i == 0 ? graph[node][1].to : graph[node][0].to, node);
            int otherleaf2 = findleaf(i == 2 ? graph[node][1].to : graph[node][2].to, node);
            if (child == parent) continue;
            dfs(child, node);
            leaves[node].push_back(findleaf(child, node));
            if (leaves[child].size() < 2) {
                //printf("%d: %d %d %d\n", node, child, otherleaf, otherleaf2);
                child = leaves[child][0];
                ops.push_back(make_op(child, otherleaf, edgewt / 2));
                ops.push_back(make_op(otherleaf, otherleaf2, -(edgewt / 2)));
                ops.push_back(make_op(child, otherleaf2, edgewt / 2));
            } else {
                int cleaf = leaves[child][0];
                int cleaf2 = leaves[child][1];
                //printf("%d: %d %d %d %d\n", node, cleaf, cleaf2, otherleaf, otherleaf2);
                ops.push_back(make_op(cleaf, otherleaf, edgewt / 2));
                ops.push_back(make_op(cleaf2, otherleaf2, edgewt / 2));
                ops.push_back(make_op(cleaf, cleaf2, -(edgewt / 2)));
                ops.push_back(make_op(otherleaf, otherleaf2, -(edgewt / 2)));
            }
        }
    }
}

int main()
{
    scanf("%d", &n); int anyval = 0;
    for (int i = 1; i < n; i++) {
        int u, v, val; scanf("%d%d%d", &u, &v, &val); anyval = val;
        if (n == 2) {
            printf("YES\n1\n1 2 %d", val); return 0;
        }
        Edge e; e.to = v; e.val = val;
        graph[u].push_back(e); e.to = u;
        graph[v].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() == 2 && graph[i][0].val != graph[i][1].val) {
            printf("NO"); return 0;
        }
    }
    printf("YES\n");
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() > 2) root = i;
    }
    if (!root) {
        vector<int> leaf;
        for (int i = 1; i <= n; i++) {
            if (graph[i].size() == 1) leaf.push_back(i);
        }
        ops.push_back(make_op(leaf[0], leaf[1], anyval));
    } else {
        dfs(root, 0);
    }
    printf("%d\n", (int)ops.size());
    for (int i = 0; i < ops.size(); i++) {
        int u = ops[i].u, v = ops[i].v, x = ops[i].x;
        printf("%d %d %d\n", u, v, x);
    }
    return 0;
}