#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Data {
    int x, y, z;
};

int n, m;
vector <vector <int> > gr;
vector <int> used;
vector <Data> res;
vector <bool> can;
vector <int> pred;

void dfs(int v, int p = -1) {
    vector <int> down;
    used[v] = 1;
    pred[v] = p;
    for (int u : gr[v]) {
        if (used[u]) continue;
        dfs(u, v);
    }
    for (int u : gr[v]) {
        if (used[u] == 1) continue;
        if (can[u] || pred[u] != v) {
            down.push_back(u);
        }
    }
//    cout << v << ":\n";
//    for (int x : down) {
//        cout << x << " ";
//    }
//    cout << "\n";
    for (int i = 0; i < down.size(); i += 2) {
        if (i == down.size() - 1) {
            if (p != -1) {
                res.push_back({down[i], v, p});
                can[v] = false;
            }
        } else {
            res.push_back({down[i], v, down[i + 1]});
        }
    }
    used[v] = 2;
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
    cin >> n >> m;
    gr.resize(n);
    can.resize(n, true);
    pred.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        dfs(i);
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.x + 1 << " " << p.y + 1 << " " << p.z + 1 << "\n";
    }
}