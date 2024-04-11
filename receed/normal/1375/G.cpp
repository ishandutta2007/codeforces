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

const int N = 200001;
vector<int> g[N];
int d1[N], d2[N];

void dfs(int v, int p) {
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        d1[v] += d2[u];
        d2[v] += d1[u];
    }
    d1[v]++;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    cout << min(d1[0], d2[0]) - 1;
}