#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<long long>> c(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }
    vector<vector<long long>> d(N+1, vector<long long>(N+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + c[i-1][j-1];
        }
    }
    auto query = [&](int ls, int le, int rs, int re) {
        return d[re][le] - d[re][ls] - d[rs][le] + d[rs][ls];
    };
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, INF));
    vector<vector<int>> choice(N+1, vector<int>(N+1, -1));
    for (int s = 0; s <= N; s++) {
        dp[s][s] = 0ll;
    }
    for (int l = 1; l <= N; l++) {
        for (int s = 0; s+l <= N; s++) {
            int e = s+l;
            for (int m = s; m < e; m++) {
                long long cur = dp[s][m] + dp[m+1][e];
                cur += query(s, m, 0, s) + query(s, m, m, N);
                cur += query(m+1, e, 0, m+1) + query(m+1, e, e, N);
                //cout << s << " " << e << " with m = " << m << ", cur is " << cur << endl;
                if (cur < dp[s][e]) {
                    dp[s][e] = cur;
                    choice[s][e] = m;
                }
            }
        }
    }
    vector<int> p(N);
    auto go = [&](auto &self, int s, int e, int from) {
        if (s == e) {
            return;
        }
        int m = choice[s][e];
        //cout << "choice " << s << " " << e << " is " << m << endl;
        p[m] = from;
        self(self, s, m, m);
        self(self, m+1, e, m);
    };
    go(go, 0, N, -1);
    for (int i = 0; i < N; i++) {
        cout << p[i]+1 << " ";
    }
    cout << "\n";
}