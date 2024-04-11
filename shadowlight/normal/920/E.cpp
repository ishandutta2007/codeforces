#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <bool> used;
vector <vector <int> > gr;

int sz = 0;
set <int> q;

void dfs(int v) {
    if (used[v]) return;
//    cout << v << "\n";
//    for (int x : q) {
//        cout << x << " ";
//    }
//    cout << "\n";
    sz++;
    used[v] = true;
    vector <int> e;
    for (int u : gr[v]) {
        q.erase(u);
    }
    while (q.size()) {
        int u = *q.begin();
        e.push_back(u);
        q.erase(q.begin());
    }
    for (int u : gr[v]) {
        if (!used[u]) {
            q.insert(u);
        }
    }
    for (int x : e) {
        dfs(x);
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
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        q.insert(i);
    }
    used.resize(n, false);
    vector <int> comps;
    //cout << "kek\n";
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        //cout << "GO\n";
        sz = 0;
        q.erase(i);
        dfs(i);
        comps.push_back(sz);
    }
    sort(comps.begin(), comps.end());
    cout << comps.size() << "\n";
    for (int x : comps) {
        cout << x << " ";
    }
}