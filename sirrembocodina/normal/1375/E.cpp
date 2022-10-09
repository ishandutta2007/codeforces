#include "bits/stdc++.h"

using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n);
    int cnt = 0;
    forn (i, n) {
        forn (j, i) {
            if (a[j] > a[i]) {
                g[i].push_back({a[j], j});
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for (int i = n - 1; i >= 0; i--) {
        sort(g[i].begin(), g[i].end());
        forn (j, g[i].size()) {
            cout << g[i][j].second + 1 << " " << i + 1 << endl;
            swap(a[g[i][j].second], a[i]);
        }
    }
    /*cerr  << endl;
    forn (i, n) {
        cerr << a[i] << " ";
    }
    cerr << endl;*/
}