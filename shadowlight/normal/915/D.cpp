#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;
vector <vector <int> > gr;

vector <int> used;
vector <int> path;

bool dfs(int v) {
    if (used[v] == 2) {
        return false;
    }
    if (used[v] == 1) {
        path.push_back(v);
        return true;
    }
    used[v] = 1;
    for (int u : gr[v]) {
        if (dfs(u)) {
            path.push_back(v);
            return true;
        }
    }
    used[v] = 2;
    return false;
}

bool fl = false;
int bv, bu;

void dfs1(int v) {
    //cout << v << " " << used[v] << "\n";
    if (used[v]) {
        if (used[v] == 1) {
            fl = false;
        }
        return;
    }
    used[v] = 1;
    for (int u : gr[v]) {
        if (v == bv && u == bu) continue;
        dfs1(u);
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
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
    }
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (dfs(i)) {
            break;
        }
    }
    if (!path.size()) {
        cout << "YES\n";
        return 0;
    }
    while (path.back() != path[0]) path.pop_back();
//    path.pop_back();
//    for (int v : path) {
//        cout << v << " ";
//    }
////    cout << "\n";
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        bv = path[i], bu = path[(i + 1) % path.size()];
        //cout << bv << " " << bu << "\n";
        fl = true;
        used.clear();
        used.resize(n, 0);
        //cout << "FORCE\n";
        for (int v = 0; v < n; v++) {
            dfs1(v);
        }
        if (fl) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}