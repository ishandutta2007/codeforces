/*
ZDRAVSTVUYTE
ESLI VI HOTITE MENYA VZLOMAT'
YA VAM SRAZU SKAZHU
TUT BAGOV NETU
UDACHNOGO VZLOMA
SPASIBO ZA VNIMANIE
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <vector <int> > gr;
vector <int> p, r;
void create(int v) {
    p[v] = v;
    r[v] = 0;
}

int get_root(int v) {
    if (v == p[v]) return v;
    return p[v] = get_root(p[v]);
}

void unite(int v, int u) {
    v = get_root(v);
    u = get_root(u);
    if (v == u) return;
    if (r[v] == r[u]) r[v]++;
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
}

vector <vector <int> > path;
int val;
int now;
void dfs(int v, int p) {
    for (int u : gr[v]) {
        if (u == p) continue;
        if (!now) {
            now = val;
            path.push_back(vector <int>(0));
           // path.back().push_back(v);
        }
        path.back().push_back(u);
        now--;
        dfs(u, v);
    }
    if (!now && p != -1) {
        now = val;
        path.push_back(vector <int>(0));
    }
    if (p != -1) {
        path.back().push_back(p);
        now--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    p.resize(n, 0);
    r.resize(n, 0);
    gr.resize(n);
    for (int i = 0; i < n; i++) {
        create(i);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (get_root(l) == get_root(r)) continue;
        gr[l].push_back(r);
        gr[r].push_back(l);
        unite(l, r);
    }
    val = 2 * n / k;
    if ((2 * n) % k) val++;
    path.push_back(vector <int> (1, 0));
    now = val - 1;
    dfs(0, -1);
    while (path.size() < k) path.push_back(vector <int> (1, 0));
    for (int i = 0; i < k; i++) {
        cout << path[i].size() << " ";
        for (int j : path[i]) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
}