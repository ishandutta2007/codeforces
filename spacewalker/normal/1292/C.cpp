#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 3001;

ll opt[NMAX][NMAX];

vector<int> stsz, cpar;
vector<vector<int>> tree;

void fillInfo(int v, int p) {
    stsz[v] = 1;
    cpar[v] = p;
    for (int child : tree[v]) {
        if (child == p) continue;
        fillInfo(child, v);
        stsz[v] += stsz[child];
    }
}

int getBlockerSum(int v, int p) {
    if (p == cpar[v]) return stsz[v];
    else return (int)stsz.size() - stsz[p];
}

ll ansWithSeed(int v, int vp, int u, int up) {
    if (opt[v][u] != -1) return opt[v][u];
    ll curContrib = getBlockerSum(v, vp) * getBlockerSum(u, up);
    ll subCase = 0;
    for (int vnext : tree[v]) {
        if (vnext == vp) continue;
        subCase = max(subCase, ansWithSeed(vnext, v, u, up));
    }
    for (int unext : tree[u]) {
        if (unext == up) continue;
        subCase = max(subCase, ansWithSeed(v, vp, unext, u));
    }
    return (opt[v][u] = curContrib + subCase);
}

int main() {
    memset(opt, -1, sizeof opt);
    int n; scanf("%d", &n);
    vector<pair<int, int>> elist;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        elist.emplace_back(--a, --b);
    }
    tree = vector<vector<int>>(n);
    stsz = cpar = vector<int>(n);
    for (auto e : elist) {
        tree[e.first].push_back(e.second);
        tree[e.second].push_back(e.first);
    }
    fillInfo(0, -1);
    ll ans = 0;
    for (auto e : elist) {
        ans = max(ans, ansWithSeed(e.first, e.second, e.second, e.first));
    }
    cout << ans << endl;
    return 0;    
}