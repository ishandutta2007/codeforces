#include <bits/stdc++.h>
using namespace std;

constexpr long long Mod = 998'244'353;

using Matrix = vector<vector<int>>;

Matrix matmul(Matrix &a, Matrix &b) {
    int N = (int) a.size();
    Matrix c(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            for (int k = 0; k < N; k++) {
                c[y][x] = ((long long)a[y][k] * b[k][x] + c[y][x]) % Mod;
            }
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> e(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    const int MaxD = 14;
    Matrix dp(2*N, vector<int>(2*N));
    for (int i = 0; i < N; i++) {
        for (int j : e[i]) {
            dp[i][j]++;
            dp[i][i+N]--;
        }
        dp[i][i+N]++;
        if (dp[i][i+N]) {
            dp[i][i+N] += Mod;
        }
    }
    for (int i = 0; i < N; i++) {
        dp[i+N][i]++;
    }

    Matrix res(2*N, vector<int>(2*N));
    for (int i = 0; i < 2*N; i++) {
        res[i][i] = 1;
    }
    for (int d = 0; d < MaxD; d++) {
        if ((K-1) & (1<<d)) {
            res = matmul(res, dp);
        }
        dp = matmul(dp, dp);
    }
    long long ans = 0ll;
    for (int i = 0; i < N; i++) {
        for (int j : e[i]) {
            ans = (ans + res[j][i] - res[i+N][i] + Mod) % Mod;
        }
    }
    cout << ans << endl;
}