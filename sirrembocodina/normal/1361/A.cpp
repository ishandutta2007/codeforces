#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<int> g[500100];
vector<int> l[500100];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> t(n);
    forn (i, n) {
        cin >> t[i];
        --t[i];
        l[t[i]].push_back(i);
    }
    forn (i, n) {
        for (int v: l[i]) {
            vector<bool> used(i);
            for (int to: g[v]) {
                if (t[to] == i) {
                    cout << -1 << endl;
                    return 0;
                }
                if (t[to] < i) {
                    used[t[to]] = true;
                }
            }
            bool ok = true;
            forn (j, i) {
                if (!used[j]) {
                    ok = false;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    forn (i, n) {
        for (int v: l[i]) {
            cout << v + 1 << " ";
        }
    }
    cout << endl;
}