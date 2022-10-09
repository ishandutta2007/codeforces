#include <bits/stdc++.h>

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool g[20][20];
int cnt = 0;
vector<bool> used;

void dfs(int v) {
    cnt++;
    used[v] = true;
    forn (i, 20) {
        if (g[v][i] && !used[i]) {
            dfs(i);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    forn (q, T) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        forn (i, 20) {
            forn (j, 20) {
                g[i][j] = false;
            }
        }
        bool bad = false;
        forn (i, n) {
            a[i] -= 'a';
            b[i] -= 'a';
            if (a[i] > b[i]) {
                bad = true;
            } else if (a[i] < b[i]) {
                g[a[i]][b[i]] = true;
                g[b[i]][a[i]] = true;
            }
        }
        if (bad) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        used.assign(20, false);
        forn (i, 20) {
            if (!used[i]) {
                cnt = 0;
                dfs(i);
                ans += cnt - 1;
            }
        }
        cout << ans << endl;
    }
}