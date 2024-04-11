#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <int> pr;
vector <vector <int> > gr;
vector <bool> used;
int n, m, d;
void dfs(int v, int p) {
    used[v] = true;
    pr[v] = p;
    int cnt = 0;
    for (int u : gr[v]) {
        if (!used[u]) {
            cnt++;
            dfs(u, v);
        }
    }
    if (p == -1) {
        if (cnt > d) {
            cout << "NO\n";
            exit(0);
        }
        for (auto u : gr[v]) {
            if (cnt == d) break;
            if (pr[u] != v) {
                pr[u] = v;
                cnt++;
            }
        }
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
    cin >> n >> m >> d;
    gr.resize(n);
    pr.resize(n);
    used.resize(n, false);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    if (gr[0].size() < d) {
        cout << "NO\n";
        return 0;
    }
    dfs(0, -1);
    cout << "YES\n";
    for (int i = 1; i < n; i++) {
        cout << i + 1 << " " << pr[i] + 1 << "\n";
    }
}