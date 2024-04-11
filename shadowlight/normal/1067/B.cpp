#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;


vector <vector <int> > gr;

vector <int> path;
int md = -1;
int maxp = -1;

void dfs(int v, int p)  {
    path.push_back(v);
    if (maxp < (int) path.size()) {
        maxp = (int) path.size();
        md = path[(int) path.size() / 2];
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    path.pop_back();
}

void dfs1(int v, int p, int st) {
    if (gr[v].size() == 1) {
        if (st != 0) {
            cout << "No\n";
            exit(0);
        }
        return;
    }
    int cnt = 0;
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs1(u, v, st - 1);
        cnt++;
    }
    if (cnt < 3) {
        cout << "No\n";
        exit(0);
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
    int n, k;
    cin >> n >> k;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (gr[i].size() == 1) {
            dfs(i, -1);
            dfs1(md, -1, k);
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}