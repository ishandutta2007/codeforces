#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
vector<vector<int>> g2, g;
vector<int> seen;
vector<int> pred;
vector<int> dept;
void dfsnorm(int v, int p = -1) {
    if (seen[v])
        return;
    seen[v] = 1;
    if (p != -1) {
        g[v].push_back(p);
        g[p].push_back(v);
    }
    for (auto i : g2[v])
        dfsnorm(i, v);
}
void dfsdep(int v, int dep = 0, int p = -1) {
    dept[v] = dep;
    pred[v] = p;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfsdep(i, dep + 1, v);
    }
}
vector<vector<int>> ans;
vector<int> cnt;
void move(int u, int v) {
    cnt[u]++;
    cnt[v]++;
    vector<int> umove;
    vector<int> vmove;
    while (dept[u] > dept[v]) {
        umove.push_back(u);
        u = pred[u];
    }
    while (dept[u] < dept[v]) {
        vmove.push_back(v);
        v = pred[v];
    }
    while (u != v) {
        umove.push_back(u);
        u = pred[u];
        vmove.push_back(v);
        v = pred[v];
    }
    reverse(all(vmove));
    umove.push_back(u);
    for (auto i : vmove)
        umove.push_back(i);
    ans.push_back(umove);
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    pred.assign(n, 0);
    cnt.assign(n, 0);
    dept.assign(n, 0);
    seen.assign(n, 0);
    g2.assign(n, {});
    g.assign(n, {});
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    dfsnorm(0);
    dfsdep(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        move(a, b);
    }
    int oddcnt = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] % 2)
            oddcnt++;
    }
    if (oddcnt != 0) {
        cout << "NO\n" << oddcnt / 2;
    } else {
        cout << "YES\n";
        for (auto i : ans) {
            cout << i.size() << '\n';
            for (auto j : i) {
                cout << j + 1 << ' ';
            }
            cout << '\n';
        }
    }
}