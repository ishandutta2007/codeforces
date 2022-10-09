#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

int n, m;
vector<string> s;

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '#';
}

void dfs(int i, int j) {
    s[i][j] = '-';
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    forn (k, 4) {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if (ok(cx, cy)) {
            dfs(cx, cy);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    s.resize(n);
    string t = "#.#";
    int cnt1 = 0;
    forn (i, n) {
        cin >> s[i];
        int k = 0;
        forn (j, m) {
            if (s[i][j] == t[k]) {
                ++k;
                if (k == 3) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        if (k == 0) {
            cnt1++;
        }
    }
    int cnt2 = 0;
    forn (j, m) {
        int k = 0;
        forn (i, n) {
            if (s[i][j] == t[k]) {
                ++k;
                if (k == 3) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        if (k == 0) {
            cnt2++;
        }
    }
    if (max(cnt1, cnt2) > 0 && min(cnt1, cnt2) == 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    forn (i, n) {
        forn (j, m) {
            if (s[i][j] == '#') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}