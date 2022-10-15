#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
//
using namespace std;

int n, m;

int degree[100005];
int answer[100005];
int uf[100005];
int prt[100005];
int depth[100005];
int weight[100005];
vector<int> graph[100005];

vector<int> component_set;

int find(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

void un(int a, int b)
{
    a = find(a); b = find(b);
    uf[a] = b;
}

void dfs(int node, int parent, int dep)
{
    component_set.push_back(node);
    prt[node] = parent;
    depth[node] = dep;
    weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            dfs(graph[node][i], node, dep+1);
            weight[node] += weight[graph[node][i]];
        }
    }
}

void paint_route(int from, int to, int val)
{
    if (depth[from] < depth[to]) {
        int t = from; from = to; to = t;
    }
    while (depth[from] > depth[to]) {
        answer[from] = val, from = prt[from];
    }
    while (from != to) {
        answer[from] = answer[to] = val;
        from = prt[from]; to = prt[to];
    }
    answer[from] = val;
}

void answer_yes(void)
{
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", answer[i]);
    printf("\n");
}

void paint_chain(int node, int parent, int val, int dec)
{
    if (val <= 0) return;
    answer[node] = val;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            paint_chain(graph[node][i], node, val-dec, dec);
            return;
        }
    }
}

bool work_component(int component_root)
{
    component_set.clear();
    dfs(component_root, 0, 0);
    vector<int> deg3;
    for (int ind = 0; ind < component_set.size(); ind++) {
        int node = component_set[ind];
        if (degree[node] >= 4) {
            answer[node] = 2;
            for (int i = 0; i < graph[node].size(); i++) {
                answer[graph[node][i]] = 1;
            }
            return true;
        } else if (degree[node] == 3) {
            deg3.push_back(node);
        }
    }
    if (deg3.size() == 0) {
        return false;
    } else if (deg3.size() >= 2) {
        for (int i = 0; i < 3; i++) {
            answer[graph[deg3[0]][i]] = 1;
            answer[graph[deg3[1]][i]] = 1;
        }
        paint_route(deg3[0], deg3[1], 2);
        return true;
    } else {
        int central = deg3[0];
        dfs(central, 0, 0);
        pair<int, int> wts[3];
        for (int i = 0; i < 3; i++) {
            wts[i] = make_pair(weight[graph[central][i]], graph[central][i]);
        }
        sort(wts, wts + 3);
        if (wts[0].first >= 2) {
            answer[central] = 3;
            paint_chain(wts[0].second, central, 2, 1);
            paint_chain(wts[1].second, central, 2, 1);
            paint_chain(wts[2].second, central, 2, 1);
            return true;
        } else if (wts[1].first >= 3) {
            answer[central] = 4;
            answer[wts[0].second] = 2;
            paint_chain(wts[1].second, central, 3, 1);
            paint_chain(wts[2].second, central, 3, 1);
            return true;
        } else if (wts[1].first == 2 && wts[2].first >= 5) {
            answer[central] = 6;
            answer[wts[0].second] = 3;
            paint_chain(wts[1].second, central, 4, 2);
            paint_chain(wts[2].second, central, 5, 1);
            return true;
        }
    }
    return false;
}

void work(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (find(u) == find(v)) {
            int ignore1, ignore2;
            for (int j = 1; j <= m - i; j++) {
                scanf("%d%d", &ignore1, &ignore2);
            }
            dfs(u, 0, 0);
            paint_route(u, v, 1);
            answer_yes(); return;
        }
        un(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++; degree[v]++;
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.push_back(find(i));
    }
    sort(roots.begin(), roots.end());
    for (int i = 0; i < n; i++) {
        if (i == 0 || roots[i] != roots[i-1]) {
            if (work_component(roots[i])) {
                answer_yes(); return;
            }
        }
    }
    printf("NO\n");
}

void cleanup(void)
{
    for (int i = 1; i <= n; i++) {
        degree[i] = 0; answer[i] = 0;
        graph[i].clear();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        work(); cleanup();
    }
    return 0;
}