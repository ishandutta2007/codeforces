#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int n, m;

vector <bool> used;
vector <int> edges;
vector <vector <pair <int, int> > > gr;
vector <int> d;

bool dfs(int v) {
    if (used[v]) return 0;
    used[v] = true;
    int st = 0;
    for (auto p : gr[v]) {
        int u = p.first, id = p.second;
        bool x = dfs(u);
        if (x) {
            edges.push_back(id);
            st++;
        }
    }
    if (st % 2 != d[v]) {
        return true;
    }
    return false;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n >> m;
    d.resize(n);
    gr.resize(n);
    int start = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        if (d[i] == -1) {
            start = i;
        }
    }
    if (start == -1) {
        if (sum % 2) {
            cout << -1;
            return 0;
        }
        start = 0;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back({u, i});
        gr[u].push_back({v, i});
    }
    used.resize(n, 0);
    dfs(start);
    cout << edges.size() << endl;
    for (int i : edges) {
        cout << i + 1 << " ";
    }
}