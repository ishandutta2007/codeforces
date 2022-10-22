#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 107;
const int Q = 28;

int win[Q][N][N];

vector <vector <pair <int, int> > > gr;

int dfs(int a, int b, int c) {
    if (win[c][a][b]) {
        return win[c][a][b];
    }
    for (auto e : gr[a]) {
        if (e.second < c) continue;
        if (dfs(b, e.first, e.second) == -1) {
            return win[c][a][b] = 1;
        }
    }
    return win[c][a][b] = -1;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        v--, u--;
        gr[v].push_back({u, c - 'a' + 1});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (dfs(i, j, 1) == 1 ? "A" : "B");
        }
        cout << "\n";
    }
}