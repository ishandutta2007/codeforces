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

const int N = 500001;
vector<int> g[N];
set<int> s[N];
int a[N], d[N];
vector<int> ord;

void dfs(int v) {
    if (d[v] || s[v].size() < a[v] - 1)
        return;
    d[v] = 1;
    ord.push_back(v);
    for (int u : g[v]) {
        if (a[u] == a[v]) {
            cout << -1;
            exit(0);
        }
        if (a[v] < a[u])
            s[u].insert(a[v]);
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, n)
        cin >> a[i];
    rep(i, n)
        dfs(i);
    rep(i, n)
        if (!d[i]) {
            cout << -1;
            return 0;
        }
    for (int i : ord)
        cout << i + 1 << ' ';
}