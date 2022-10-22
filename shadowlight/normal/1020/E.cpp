#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr, rev_gr;

vector <bool> exist;
vector <bool> erased;

int all = 0;

int last = 0;

void rec() {
    while (last < gr.size() && erased[last]) {
        last++;
    }
    if (last == gr.size()) return;
    int v = last;
    erased[v] = true;
    bool fl = false;
    for (int u : gr[v]) {
        if (erased[u]) continue;
        erased[u] = true;
    }
    rec();
    for (int u : rev_gr[v]) {
        if (exist[u]) {
            fl = true;
            break;
        }
    }
    if (!fl) {
        all++;
        exist[v] = true;
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
    rev_gr.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        rev_gr[u].push_back(v);
    }
    exist.resize(n, false);
    erased.resize(n, false);
    rec();
    cout << all << "\n";
    for (int i = 0; i < n; i++) {
        if (exist[i]) {
            cout << i + 1 << " ";
        }
    }
}