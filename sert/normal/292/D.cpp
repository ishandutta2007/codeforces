#include <bits/stdc++.h>
using namespace std;

const int N = 503;
int p[N], sz[N];

void init() {
    for (int i = 0; i < N; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

int fnd(int v) {
    return (p[v] == v ? v : p[v] = fnd(p[v]));
}

bool merg(int v1, int v2) {
    if (v1 == -1 || v2 == -1) return false;
    v1 = fnd(v1), v2 = fnd(v2);
    if (v1 == v2) return false;
    if (sz[v1] > sz[v2]) swap(v1, v2);
    p[v1] = v2;
    sz[v2] += sz[v1];
    return true;
}

vector<pair<int, int>> getPrefST(const vector<pair<int, int>> &e) {
    init();
    vector<pair<int, int>> ans;
    for (const auto &q : e) {
        int v1 = q.first, v2 = q.second;
        if (merg(v1, v2)) {
            ans.emplace_back(v1, v2);
        } else {
            ans.emplace_back(-1, -1);
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
        e[i].first--;
        e[i].second--;
    }
    auto pref = getPrefST(e);
    reverse(e.begin(), e.end());
    auto suf = getPrefST(e);
    reverse(e.begin(), e.end());

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        init();
        for (int i = 0; i < l - 1; i++) 
            merg(pref[i].first, pref[i].second);
        for (int i = r; i < m; i++) 
            merg(suf[m - i - 1].first, suf[m - i - 1].second);

        int ans = 0;
        for (int i = 0; i < n; i++) ans += (int)(i == p[i]);
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 1;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}