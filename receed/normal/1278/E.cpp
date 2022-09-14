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

const int N = 500002;
vector<int> g[N];
int l[N], r[N];
int k = 1;

void dfs(int v, int p) {
    for (int u : g[v])
        if (u != p)
            l[u] = ++k;
    r[v] = ++k;
    reverse(all(g[v]));
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    l[0] = 1;
    dfs(0, 0);
    rep(i, n)
        cout << l[i] << ' ' << r[i] << '\n';
}