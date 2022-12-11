#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void go(int v, const vector<vector<int>> &es, vector<bool> &u, set<int> &bad) {
    u[v] = true;    
    set<int> me;
    for (int w : es[v]) me.insert(w);
    vector<int> del;
    for (int w : bad) if (me.find(w) == me.end()) del.push_back(w);
    for (int w : del) bad.erase(w);
    for (int w : del) go(w, es, u, bad);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> es(n);
    while (m--) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    for (int i = 0; i < n; i++) sort(all(es[i]));

    vector<bool> u(n, false);
    int cmp = 0;
    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        cmp++;
        set<int> bad;
        for (int j = 0; j < n; j++) bad.insert(j);
        go(i, es, u, bad);
    }

    cout << cmp - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}