#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;

vector<int> g[N];
int sz[N];
vector<int> lv[N];
vector<pii> a;

void dfs(int v, int p, int deep) {
    sz[v] = 1;
//    lv[deep].push_back(v);

    for(auto u : g[v]) {
        if(u != p) {
            dfs(u, v, deep + 1);
            sz[v] += sz[u];
        }
    }

    a.emplace_back(deep, sz[v]);
}

bool cmp(int v, int u) {
    return sz[v] < sz[u];
}

bool cmp1(pii x, pii y) {
    return x.f - x.s > y.f - y.s;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0, 0);

//    for(int i = 0; i < n; i++)
//        sort(lv[i].begin(), lv[i].end(), cmp);

    sort(a.begin(), a.end(), cmp1);

    li ans = 0;
    for(int i = 0; i < k; i++) {
        ans += a[i].f - a[i].s + 1;
    }

    cout << ans;
}

int main() {
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}