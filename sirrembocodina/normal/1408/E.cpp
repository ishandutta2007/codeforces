#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> p, sz;

int get_root(int v) {
    if (p[v] == -1) {
        return v;
    }
    return p[v] = get_root(p[v]);
}

bool unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return false;
    }
    if (sz[a] < sz[b]) {
        p[a] = b;
        sz[b] += sz[a];
    } else {
        p[b] = a;
        sz[a] += sz[b];
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    forn (i, n) {
        cin >> a[i];
    }
    forn (i, m) {
        cin >> b[i];
    }
    vector<pair<int, pair<int, int>>> e;
    forn (i, n) {
        int k;
        cin >> k;
        forn (j, k) {
            int x;
            cin >> x;
            x--;
            e.push_back({-a[i] - b[x], {i, n + x}});
        }
    }
    p.assign(n + m, -1);
    sz.assign(n + m, 1);
    sort(e.begin(), e.end());
    int ans = 0;
    forn (i, e.size()) {
        if (!unite(e[i].second.first, e[i].second.second)) {
            ans -= e[i].first;
        }
    }
    cout << ans << endl;
}