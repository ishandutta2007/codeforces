#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

const int Q = 26;

void add(int &x, int y) {
    x += y;
    if (x >= INF) {
        x -= INF;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[n + 1][Q][3];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < Q; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
                if (!i && !k) {
                    dp[i][j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Q; j++) {
            for (int k = 0; k < 3; k++) {
                if (k < 2) {
                    add(dp[i][j][1], dp[i - 1][j][k]);
                }
                if (s[i - 1] - 'a' == j) {
                    add(dp[i][j][k ? 2 : 0], dp[i - 1][j][k]);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < Q; i++) {
        for (int k = 0; k < 3; k++) {
            add(sum, dp[n][i][k]);
        }
    }
    add(sum, INF - Q);
    add(sum, 1);
    cout << sum;
}