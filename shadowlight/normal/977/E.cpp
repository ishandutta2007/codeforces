#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;
vector <vector <int> > gr;

bool isCycle = false;
vector <bool> used;

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    if (gr[v].size() != 2) {
        isCycle = false;
    }
    for (int u : gr[v]) {
        dfs(u);
    }
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
    used.resize(n, false);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        isCycle = true;
        dfs(i);
        if (isCycle) {
            cnt++;
        }
    }
    cout << cnt;
}