#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m);
        forn (i, n * m) {
            cin >> a[i];
        }
        vector<int> as = a;
        sort(as.begin(), as.end());
        map<int, int> M;
        forn (i, n * m) {
            M[as[i]] = i;
        }
        vector<vector<int>> h(n * m);
        forn (i, n * m) {
            a[i] = M[a[i]];
            h[a[i]].push_back(i);
        }
        vector<vector<int>> table(n, vector<int>(m));
        int cur = 0;
        int x = 0, y = 0;
        forn (i, n * m) {
            //cerr << i <<endl;
            //cerr << x << ' ' << y << endl;
            sort(h[i].rbegin(), h[i].rend());
            if (y + h[i].size() <= m) {
                forn (j, h[i].size()) {
                    table[x][y + j] = h[i][j];
                }
                y += h[i].size();
                if (y == m) {
                    x++;
                    y = 0;
                }
                continue;
            }
            forn (j, m - y) {
                table[x][m - 1 - j] = h[i].back();
                h[i].pop_back();
            }
            x++;
            x += h[i].size() / m;
            y = h[i].size() % m;
            forn (j, h[i].size() % m) {
                table[x][j] = h[i][j];
            }
        }
        int ans = 0;
        forn (i, n) {
            forn (j, m) {
                forn (k, j) {
                    ans += table[i][j] > table[i][k];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}