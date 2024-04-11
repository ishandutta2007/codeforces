#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int v, u, w;
};

const int INF = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <edge> gr;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        gr.push_back({v, u, w});
    }
    vector <int> used(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        used[v] = 1;
    }
    int minr = INF;
    for (int i = 0; i < m; i++) {
        if (used[gr[i].v] && used[gr[i].u]) continue;
        if ((used[gr[i].v] || used[gr[i].u]) && minr > gr[i].w) {
            minr = gr[i].w;
        }
    }
    if (minr == INF) {
        cout << -1;
        return 0;
    }
    cout << minr;
}