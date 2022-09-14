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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 100001;
vector<int> g[N];
int f[2];

void dfs(int v, int p, int h) {
    if (g[v].size() == 1)
        f[h] = 1;
    for (int u : g[v])
        if (u != p)
            dfs(u, v, h ^ 1);
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
    int mx = n - 1, cc, mn = 1;
    rep(i, n) {
        cc = 0;
        for (int j : g[i])
            if (g[j].size() == 1)
                cc++;
        mx -= max(cc - 1, 0);
    }
    dfs(0, 0, 0);
    if (f[0] && f[1])
        mn = 3;
    cout << mn << ' ' << mx;

}