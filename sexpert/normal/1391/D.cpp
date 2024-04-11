#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    if(n == 1 || m == 1) {
        cout << "0\n";
        return 0;
    }
    vector<string> grid(n);
    for(auto &s : grid)
        cin >> s;
    vector<vector<int>> gr;
    if(n < m) {
        swap(n, m);
        gr.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                gr[i][j] = (grid[j][i] - '0');
            }
        }
    }
    else {
        gr.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                gr[i][j] = (grid[i][j] - '0');
    }
    vector<int> dp(1 << m), tmp(1 << m);
    for(int ms = 0; ms < (1 << m); ms++) {
        int x = gr[0][0] + 2*gr[0][1] + (m == 3 ? 4*gr[0][2] : 0);
        dp[ms] = __builtin_popcount(ms ^ x);
    }
    auto get = [](int x, int p) { return ((x & (1 << p)) >> p);};
    for(int i = 1; i < n; i++) {
        for(int ms = 0; ms < (1 << m); ms++)
            tmp[ms] = INF;
        for(int pm = 0; pm < (1 << m); pm++) {
            for(int cm = 0; cm < (1 << m); cm++) {
                bool good = true;
                for(int j = 0; j < m - 1; j++) {
                    int x = get(pm, j) ^ get(pm, j + 1) ^ get(cm, j) ^ get(cm, j + 1);
                    if(!x)
                        good = false;
                }
                if(!good)
                    continue;
                int x = gr[i][0] + 2*gr[i][1] + (m ==3 ? 4*gr[i][2] : 0);
                tmp[cm] = min(tmp[cm], dp[pm] + __builtin_popcount(cm ^ x));
            }
        }
        dp = tmp;
    }
    int ans = INF;
    for(int i = 0; i < (1 << m); i++)
        ans = min(ans, dp[i]);
    cout << ans << '\n';
}