#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> g;
vector<int> gb;
int dfs(int v, int p) {
    vector<int> a(4);
    for (auto i : g[v]) {
        if (i != p) {
            gb[i] = dfs(i, v);
            a[gb[i]]++;
        }
    }
    if (a[0])
        return 0;
    if (a[1] == 0 and a[2] == 0 and a[3] == 0) {
        return 1;
    }
    int x = 0;
    if (p == -1) {
        if ((a[1] + a[2] + a[3]) % 2) {
            if (abs(a[1] - a[2] - 1) <= a[3])
                x += 3;
        } else {
            if (abs(a[1] - a[2]) <= a[3])
                x += 3;
        }
        return x;
    } else if ((a[1] + a[2] + a[3] + 1) % 2) {
        if (abs(a[1] - a[2] - 2) <= a[3])
            x += 2;
        if (abs(a[1] - a[2]) <= a[3])
            x += 1;
    } else {
        if (abs(a[1] - a[2] - 1) <= a[3])
            x += 2;
        if (abs(a[1] - a[2] + 1) <= a[3])
            x += 1;
    }
    //cerr << x << endl;
    //cout << v << ' ' << x << endl;
    return x;
}
vector<pair<int, int>> ed;
void dfs2(int v, int p) {
    vector<int> a(4);
    a[gb[v]]++;
    for (auto i : g[v]) {
        if (i != p) {
            a[gb[i]]++;
        }
    }
    for (auto i : g[v]) {
        if (i != p and gb[i] == 3) {
            if (a[1] > a[2]) {
                a[2]++;
                gb[i] = 2;
            } else {
                a[1]++;
                gb[i] = 1;
            }
        }
    }
}
void dfs3(int v, int p) {
    vector<int> a(4);
    vector<int> ed1, ed2;
    if (p != -1) {
        if (gb[v] == 1)
            ed1.push_back(p);
        else
            ed2.push_back(p);
    }
    for (auto i : g[v]) {
        if (i == p)
            continue;
        if (gb[i] == 1)
            ed1.push_back(i);
        else
            ed2.push_back(i);
    }
    bool ok1 = (ed1.size() + ed2.size()) % 2;
    while (ed1.size() + ed2.size() != 0) {
        if (ok1) {
            if (ed1.back() == p) {
                cout << v + 1 << ' ' << p + 1 << '\n';
            } else {
                dfs3(ed1.back(), v);
            }
            ed1.pop_back();
        } else {
            if (ed2.back() == p) {
                cout << v + 1 << ' ' << p + 1 << '\n';
            } else {
                dfs3(ed2.back(), v);
            }
            ed2.pop_back();
        }
        ok1 = 1 - ok1;
    }
}
void solve() {
    int n;
    cin >> n;
    g.assign(n, {});
    ed.clear();
    gb.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    gb[0] = dfs(0, -1);
    if (gb[0] == 0 or gb[0] == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs2(0, -1);
    if (gb[0] == 3)
        gb[0] = 2;
    dfs2(0, -1);
    dfs3(0, -1);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}