#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <vector <int> > gr;

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
    vector <int> res;
    vector <bool> used(n , 0);
    set <int> q;
    q.insert(0);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(v);
        res.push_back(v);
        used[v] = true;
        for (int u : gr[v]) {
            if (used[u]) continue;
            q.insert(u);
        }
    }
    for (int x : res) {
        cout << x + 1 << " ";
    }
}