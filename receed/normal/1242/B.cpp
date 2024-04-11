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

const int N = 100002;
int used[N];
set<pair<int, int>> e;
set<int> cu;

void dfs(int v) {
    used[v] = 1;
    vector<int> li;
    for (int u : cu)
        if (!e.count({v, u}))
            li.push_back(u);
    for (int i : li)
        cu.erase(i);
    for (int i : li)
        if (!used[i])
            dfs(i);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        e.insert({u, v});
        e.insert({v, u});
    }
    int ans = 0;
    rep(i, n)
        cu.insert(i);
    rep(i, n)
        if (cu.count(i)) {
            cu.erase(i);
            ans++;
            dfs(i);
        }
    cout << ans - 1;
}