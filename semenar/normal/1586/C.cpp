#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> board(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') board[i][j] = true;
        }
    }

    vector<vector<int>> rchb1(n, vector<int>(m, m)), rchb2(n, vector<int>(m, m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) {
                rchb1[i][j] = j;
                if (i == 0 || j == 0) rchb1[i][j] = -1;
                else rchb1[i][j] = min(rchb1[i][j], min(rchb1[i][j - 1], rchb1[i - 1][j]));
            }
            rchb2[i][j] = j;
            if (i == 0 || j == 0) rchb2[i][j] = -1;
            else rchb2[i][j] = min(rchb2[i][j], min(rchb1[i][j - 1], rchb1[i - 1][j]));
        }
    }

    vector<int> prf_col(m + 1, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) prf_col[j + 1] = max(prf_col[j + 1], rchb1[i][j]);
            else prf_col[j + 1] = max(prf_col[j + 1], rchb2[i][j]);
        }
    }
    vector<int> mx_cnt(m + 1);
    for (int i = 1; i <= m; i++) {
        if (prf_col[i] == m) mx_cnt[i]++;
        mx_cnt[i] += mx_cnt[i - 1];
        if (prf_col[i] == m) prf_col[i] = -1;
        prf_col[i] = max(prf_col[i], prf_col[i - 1]);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        if (mx_cnt[y] != mx_cnt[x + 1] || prf_col[y] > x) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }

    return 0;
}