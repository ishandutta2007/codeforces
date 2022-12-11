#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<vector<int>> graph;
vector<bool> vis;
vector<pair<int, int>> qs;
vector<vector<int>> pathFront, pathBack;

void dfs(int v, int p) {
//    printf("dfs %d %d\n", v, p);
    vis[v] = true;
    for (int nxt : graph[v]) {
        if (nxt == p || vis[nxt]) continue;
        dfs(nxt, v);
    }
    for (int i = 0; i < qs.size(); ++i) {
        if (qs[i].first == v && qs[i].second == v) {
//            printf("locking path %d\n", i);
            pathFront[i].push_back(v);
        } else if (qs[i].first == v) {
//            printf("push first %d\n", i);
            qs[i].first = p;
            pathFront[i].push_back(v);
        } else if (qs[i].second == v) {
//            printf("push second %d\n", i);
            qs[i].second = p;
            pathBack[i].push_back(v);
        }
    }
//    printf("end dfs %d\n", v);
}

void constructPaths(vector<vector<int>> &_graph, vector<pair<int,int>> &_qs) {
    graph = _graph; qs = _qs;
    int n = graph.size(), q = qs.size();
    par.assign(n, -2);
    vis.assign(n, false);
    pathFront.assign(q, vector<int>());
    pathBack.assign(q, vector<int>());
    dfs(0, -1);
    for (int i = 0; i < qs.size(); ++i) {
        reverse(begin(pathBack[i]), end(pathBack[i]));
    }
    for (int i = 0; i < qs.size(); ++i) {
        printf("%lu\n", pathFront[i].size() + pathBack[i].size());
        for (int v : pathFront[i]) printf("%d ", v + 1);
        for (int v : pathBack[i]) printf("%d ", v + 1);
        printf("\n");
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<pair<int, int>> qs;
    set<int> oddCount;
    auto toggle = [&] (int v) {
        if (oddCount.count(v) == 0) oddCount.insert(v);
        else oddCount.erase(v);
    };
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        qs.emplace_back(a, b);
        toggle(a); toggle(b);
    }
    vector<int> odds(begin(oddCount), end(oddCount));
    if (odds.size() == 0) {
        printf("YES\n");
        constructPaths(graph, qs);
    } else {
        printf("NO\n%lu\n", odds.size() / 2);
    }
}