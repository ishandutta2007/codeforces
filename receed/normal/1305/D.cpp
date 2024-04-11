#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1001;
vector<int> g[N];
int w;

int q(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    cin >> w;
    return w;
}

int dfs(int v, int p) {
    vector<int> li;
    for (int u : g[v])
        if (u != p)
            li.push_back(u);
    while (li.size() >= 2) {
        q(li[li.size() - 2], li.back());
        if (w == v) {
            li.pop_back();
            li.pop_back();
        }
        else
            return dfs(w, v);
    }
    if (li.size() == 0)
        return v;
    int u = li[0];
    if (g[u].size() == 1)
        return q(u, v);
    if (g[u].back() == v)
        g[u].pop_back();
    q(v, g[u].back());
    if (w == v)
        return v;
    if (w == u) {
        g[u].pop_back();
        return dfs(u, v);
    }
    return dfs(g[u].back(), u);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
	int n, u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int r = dfs(1, -1);
    cout << "! " << r << endl;
}