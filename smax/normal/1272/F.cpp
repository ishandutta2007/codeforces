#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, m, dp[201][201][201];
string s, t;

struct State {
    int i, j, k;
    char c = 'E';
} pred[201][201][201];

int solve(int i, int j, int k) {
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (i == n && j == m && k == 0)
        return dp[i][j][k] = 0;

    dp[i][j][k] = INF;
    if (k < 200) {
        int newI = i, newJ = j;
        if (newI < n && s[newI] == '(')
            newI++;
        if (newJ < m && t[newJ] == '(')
            newJ++;
        int ret = solve(newI, newJ, k + 1) + 1;
        if (ret < dp[i][j][k]) {
            dp[i][j][k] = ret;
            pred[i][j][k].i = newI;
            pred[i][j][k].j = newJ;
            pred[i][j][k].k = k + 1;
            pred[i][j][k].c = '(';
        }
    }
    if (k > 0) {
        int newI = i, newJ = j;
        if (newI < n && s[newI] == ')')
            newI++;
        if (newJ < m && t[newJ] == ')')
            newJ++;
        int ret = solve(newI, newJ, k - 1) + 1;
        if (ret < dp[i][j][k]) {
            dp[i][j][k] = ret;
            pred[i][j][k].i = newI;
            pred[i][j][k].j = newJ;
            pred[i][j][k].k = k - 1;
            pred[i][j][k].c = ')';
        }
    }

    return dp[i][j][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s >> t;

    n = s.length(), m = t.length();
    memset(dp, -1, sizeof(dp));

    solve(0, 0, 0);

    int i = 0, j = 0, k = 0;
    while (pred[i][j][k].c != 'E') {
        State st = pred[i][j][k];
        cout << st.c;
        i = st.i, j = st.j, k = st.k;
    }
    cout << "\n";

    return 0;
}