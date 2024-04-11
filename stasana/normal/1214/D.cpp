#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int v, f, c;

    Edge(int v, int f, int c)
        : v(v), f(f), c(c) {}

    int get_c() {
        return c - f;
    }
};

const int INF = 10;
const int N = 2'000'666;
int S, T;

vector<Edge> edges;
vector<int> graph[N];
int used[N];
int timer = 0;

inline void add_edge(int v, int u, int c) {
    graph[v].emplace_back(edges.size());
    edges.emplace_back(u, 0, c);
    graph[u].emplace_back(edges.size());
    edges.emplace_back(v, 0, 0);
}

int dfs(int v, int min_c) {
    if (v == T) {
        return min_c;
    }
    used[v] = timer;
    for (int id : graph[v]) {
        if (edges[id].get_c() == 0) {
            continue;
        }
        if (used[edges[id].v] == timer) {
            continue;
        }
        int x = dfs(edges[id].v, min(min_c, edges[id].get_c()));
        if (x) {
            edges[id].f += x;
            edges[id ^ 1].f -= x;
            return x;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    S = N / 2;
    T = (n - 1) * m + m - 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                add_edge(i * m + j, i * m + j + N / 2, 1);
            }
            if (i != n - 1) {
                add_edge(i * m + j + N / 2, (i + 1) * m + j, 1);
            }
            if (j != m - 1) {
                add_edge(i * m + j + N / 2, i * m + j + 1, 1);
            }
        }
    }
    ++timer;
    while (dfs(S, INF)) {
        ++timer;
    }

    int flow = 0;
    for (int i : graph[S]) {
        flow += edges[i].f;
    }
    cout << flow << endl;
    return 0;
}