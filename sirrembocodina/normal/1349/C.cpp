
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

int n, m;

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> n >> m >> t;
    vector<string> s(n);
    forn (i, n) {
        cin >> s[i];
    }
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(m, 2e18));
    forn (i, n) {
        forn (j, m) {
            bool was = false;
            forn (k, 4) {
                if (ok(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == s[i][j]) {
                    was = true;
                }
            }
            if (was) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        forn (k, 4) {
            int cx = x + dx[k], cy = y + dy[k];
            if (ok(cx, cy) && d[cx][cy] > d[x][y] + 1) {
                d[cx][cy] = d[x][y] + 1;
                q.push(make_pair(cx, cy));
            }
        }
    }
    forn (i, t) {
        int x, y, p;
        cin >> x >> y >> p;
        --x; --y;
        p -= d[x][y];
        if (p < 0) {
            cout << s[x][y] - '0' << endl;
        } else {
            cout << (p + s[x][y] - '0') % 2 << endl;
        }
    }
}