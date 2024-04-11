#include "bits/stdc++.h"

using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        forn (i, n) {
            forn (j, m) {
                cin >> a[i][j];
            }
        }
        bool ok2 = true;
        forn (i, n) {
            forn (j, m) {
                int cnt = 0;
                forn (k, 4) {
                    int x = i + dx[k], y = j + dy[k];
                    if (ok(x, y)) {
                        cnt++;
                    }
                }
                if (a[i][j] > cnt) {
                    ok2 = false;
                }
                a[i][j] = cnt;
            }
        }
        if (!ok2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        forn (i, n) {
            forn (j, m) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}