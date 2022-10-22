#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;

int n;

vector <int> path;

void dfs(int v, int p = -1) {
    path.push_back(v);
    if (v == n - 1) {
        for (int x : path) {
            cout << x + 1 << " ";
        }
        exit(0);
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    path.pop_back();
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
    cin >> n;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gr[p].push_back(i);
    }
    dfs(0);
}