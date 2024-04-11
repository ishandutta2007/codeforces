#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

vector <vector <int> > d;
vector <vector <int> > gr;
vector <int> used;
vector <int> a;

void go(int v) {
    if (used[v] == 1) {
        cout << -1;
        exit(0);
    }
    if (used[v]) {
        return;
    }
    used[v] = 1;
    for (int u : gr[v]) {
        go(u);
        for (int i = 0; i < Q; i++) {
            d[v][i] = max(d[v][i], d[u][i] + (i == a[v] ? 1 : 0));
        }
    }
    d[v][a[v]] = max(d[v][a[v]], 1);
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
    int n, m;
    cin >> n >> m;
    d.resize(n, vector <int> (Q, 0));
    gr.resize(n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
    }
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        go(i);
    }
    int maxk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Q; j++) {
            maxk = max(d[i][j], maxk);
        }
    }
    cout << maxk;
}