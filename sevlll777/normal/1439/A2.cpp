#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
vector<vector<int>> ans;
vector<string> F;

void solve22(int i, int j) {
    int c = (F[i][j] - '0') + (F[i + 1][j] - '0') + (F[i][j + 1] - '0') + (F[i + 1][j + 1] - '0');
    if (c == 3) {
        if (F[i][j] == '0') {
            ans.pb({i + 1, j, i, j + 1, i + 1, j + 1});
        } else if (F[i + 1][j] == '0') {
            ans.pb({i, j, i, j + 1, i + 1, j + 1});
        } else if (F[i][j + 1] == '0') {
            ans.pb({i + 1, j, i, j, i + 1, j + 1});
        } else {
            ans.pb({i + 1, j, i, j + 1, i, j});
        }
    }
    if (c == 2) {
        if (F[i][j] == '1') {
            ans.pb({i + 1, j, i, j + 1, i + 1, j + 1});
        }
        if (F[i + 1][j] == '1') {
            ans.pb({i, j, i, j + 1, i + 1, j + 1});
        }
        if (F[i][j + 1] == '1') {
            ans.pb({i + 1, j, i, j, i + 1, j + 1});
        }
        if (F[i + 1][j + 1] == '1') {
            ans.pb({i + 1, j, i, j + 1, i, j});
        }
    }
    if (c == 4) {
        ans.pb({i + 1, j, i, j + 1, i + 1, j + 1});
        ans.pb({i, j, i, j + 1, i + 1, j + 1});
        ans.pb({i + 1, j, i, j, i + 1, j + 1});
        ans.pb({i + 1, j, i, j + 1, i, j});
    }
    if (c == 1) {
        if (F[i][j] == '0') {
            ans.pb({i + 1, j, i, j + 1, i + 1, j + 1});
        }
        if (F[i + 1][j] == '0') {
            ans.pb({i, j, i, j + 1, i + 1, j + 1});
        }
        if (F[i][j + 1] == '0') {
            ans.pb({i + 1, j, i, j, i + 1, j + 1});
        }
        if (F[i + 1][j + 1] == '0') {
            ans.pb({i + 1, j, i, j + 1, i, j});
        }
    }
    for (int ii = i; ii <= i + 1; ii++) {
        for (int jj = j; jj <= j + 1; jj++) {
            F[ii][jj] = '0';
        }
    }
}

void solve23(int i, int j) {
    int c = 0;
    for (int ii = i; ii <= i + 1; ii++) {
        for (int jj = j; jj <= j + 2; jj++) {
            c += (F[ii][jj] - '0');
        }
    }
    if (c == 6) {
        ans.pb({i, j, i + 1, j, i, j + 1});
        ans.pb({i, j + 2, i + 1, j + 2, i + 1, j + 1});
        return;
    }
    int cc = 0;
    for (int ii = i; ii <= i + 1; ii++) {
        for (int jj = j; jj <= j + 1; jj++) {
            cc += (F[ii][jj] - '0');
        }
    }
    if (cc == 4) {
        solve22(i, j + 1);
        solve22(i, j);
    } else {
        solve22(i, j);
        solve22(i, j + 1);
    }
}

void solve32(int i, int j) {
    int c = 0;
    for (int ii = i; ii <= i + 2; ii++) {
        for (int jj = j; jj <= j + 1; jj++) {
            c += (F[ii][jj] - '0');
        }
    }
    if (c == 6) {
        ans.pb({i, j, i + 1, j, i, j + 1});
        ans.pb({i + 1, j + 1, i + 2, j, i + 2, j + 1});
        return;
    }
    int cc = 0;
    for (int ii = i; ii <= i + 1; ii++) {
        for (int jj = j; jj <= j + 1; jj++) {
            cc += (F[ii][jj] - '0');
        }
    }
    if (cc == 4) {
        solve22(i + 1, j);
        solve22(i, j);
    } else {
        solve22(i, j);
        solve22(i + 1, j);
    }
}

void solve33(int i, int j) {
    if (F[i][j] == '1') {
        ans.pb({i, j, i + 1, j, i + 1, j + 1});
        F[i][j] = '0';
        F[i + 1][j] = '0'+(F[i + 1][j] == '0');
        F[i + 1][j + 1] = '0'+(F[i + 1][j + 1] == '0');
    }
    if (F[i][j + 1] == '1') {
        ans.pb({i, j + 1, i + 1, j + 1, i + 1, j + 2});
        F[i][j + 1] = '0';
        F[i + 1][j + 1] = '0'+(F[i + 1][j + 1] == '0');
        F[i + 1][j + 2] = '0'+(F[i + 1][j + 2] == '0');
    }
    if (F[i][j + 2] == '1') {
        ans.pb({i, j + 2, i + 1, j + 1, i + 1, j + 2});
        F[i][j + 2] = '0';
        F[i + 1][j + 1] = '0'+(F[i + 1][j + 1] == '0');
        F[i + 1][j + 2] = '0'+(F[i + 1][j + 2] == '0');
    }
    solve23(i + 1, j);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        F.assign(n, "");
        for (int i = 0; i < n; i++) cin >> F[i];
        ans = {};
        if (n % 2 == 0 && m % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    solve22(i, j);
                }
            }
        } else if (n % 2 == 1 && m % 2 == 1) {
            for (int i = 0; i < n - 3; i += 2) {
                for (int j = 0; j < m - 3; j += 2) {
                    solve22(i, j);
                }
            }
            for (int i = 0; i < n - 3; i += 2) {
                solve23(i, m - 3);
            }
            for (int j = 0; j < m - 3; j += 2) {
                solve32(n - 3, j);
            }
            solve33(n - 3, m - 3);
        } else if (n % 2 == 1) {
            for (int i = 0; i < n - 3; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    solve22(i, j);
                }
            }
            for (int j = 0; j < m; j += 2) {
                solve32(n - 3, j);
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m - 3; j += 2) {
                    solve22(i, j);
                }
            }
            for (int i = 0; i < n; i += 2) {
                solve23(i, m - 3);
            }
        }

        cout << ans.size() << '\n';
        for (auto tt : ans) {
            for (auto x : tt) cout << x + 1 << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}