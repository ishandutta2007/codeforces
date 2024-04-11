#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef unsigned long long ull;

int mod = 998244353;
int r = 0;
vector<vector<int>> a;
vector<vector<int>> b;

bool cmp(int i, int j) {
    return a[i][r] < a[j][r];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    b.resize(n, vector<int>(m));
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    forn (i, n) {
        forn (j, m) {
            cin >> b[i][j];
        }
    }
    ull one = 1;
    vector<vector<ull>> w(m, vector<ull>((n - 2) / 64 + 1));
    vector<vector<ull>> nw(m, vector<ull>((n - 2) / 64 + 1));
    forn (j, m) {
        for (int i = 0; i < n - 1; i++) {
            if (b[i + 1][j] > b[i][j]) {
                nw[j][i >> 6] |= one << (i & 63);
            } else if (b[i + 1][j] < b[i][j]) {
                w[j][i >> 6] |= one << (i & 63);
            }
        }
    }
    vector<ull> mask((n - 2) / 64 + 1);
    vector<bool> used(m);
    vector<int> rows;
    while (true) {
        bool was = false;
        forn (j, m) {
            if (used[j]) {
                continue;
            }
            bool ok = true;
            for (int i = 0; i < w[j].size(); i++) {
                if ((w[j][i] | mask[i]) != mask[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            used[j] = true;
            was = true;
            rows.push_back(j);
            for (int i = 0; i < nw[j].size(); i++) {
                mask[i] |= nw[j][i];
            }
        }
        if (!was) {
            break;
        }
    }
    vector<int> inds(n);
    forn (i, n) {
        inds[i] = i;
    }
    reverse(rows.begin(), rows.end());
    for (int row: rows) {
        r = row;
        stable_sort(inds.begin(), inds.end(), cmp);
    }
    forn (i, n) {
        forn (j, m) {
            if (b[i][j] != a[inds[i]][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << rows.size() << endl;
    for (int row: rows) {
        cout << row + 1 << ' ';
    }
    cout << endl;
}