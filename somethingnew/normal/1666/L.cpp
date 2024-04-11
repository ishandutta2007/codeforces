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
vector<int> road;
int s;
vector<int> P;
int t = 1;
vector<int> seen;
vector<vector<int>> g;
void YES(int v) {
    cout << "Possible\n";
    vector<int> road1;
    road1.push_back(v);
    do {
        v = P[v];
        road1.push_back(v);
    } while (v != s);
    reverse(all(road1));
    cout << road1.size() << '\n';
    for (auto i : road1)
        cout << i + 1 << ' ';
    cout << '\n';
    cout << road.size() << '\n';
    for (auto i : road)
        cout << i + 1 << ' ';
    exit(0);
}
void dfs(int v, int p) {
    if (v == s)
        return;
    if (seen[v] == t)
        return;
    road.push_back(v);
    if (seen[v] != 0) YES(v);
    P[v] = p;
    seen[v] = t;
    for (auto i : g[v]) {
        dfs(i, v);
    }
    road.pop_back();
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m >> s;s--;
    P.assign(n, {});
    seen.assign(n, 0);
    g.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }
    road.push_back(s);
    for (auto i : g[s]) {
        dfs(i, s);
        t++;
    }
    cout << "Impossible";
}