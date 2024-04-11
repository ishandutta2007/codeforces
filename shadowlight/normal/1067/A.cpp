#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 998244353;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int Q = 207;

void add(int &x, int y) {
    x += y;
    if (x < 0) {
        x += INF;
    }
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
    vector <vector <int> > dp(Q, vector <int> (2, 0));
    int x;
    cin >> x;
    if (x == -1) {
        for (int i = 1; i <= 200; i++) {
            dp[i][1] = 1;
        }
    } else {
        dp[x][1] = 1;
    }
    for (int i = 1; i < n; i++) {
        cin >> x;
        vector <vector <int> > ndp(Q, vector <int> (2, 0));
        if (x != -1) {
            for (int y = 1; y < x; y++) {
                add(ndp[x][1], dp[y][0]);
                add(ndp[x][1], dp[y][1]);
            }
            for (int y = x + 1; y <= 200; y++) {
                add(ndp[x][0], dp[y][0]);
            }
            add(ndp[x][0], dp[x][0]);
            add(ndp[x][0], dp[x][1]);
        } else {
            vector <int> sum0(Q, 0), sum1(Q, 0);
            for (int k = 1; k < Q; k++) {
                add(sum0[k], sum0[k - 1] + dp[k][0]);
                add(sum1[k], sum1[k - 1] + dp[k][1]);
            }
            for (int x = 1; x <= 200; x++) {
                add(ndp[x][1], sum0[x - 1]);
                add(ndp[x][1], sum1[x - 1]);
                add(ndp[x][0], sum0[Q - 1] - sum0[x]);
                add(ndp[x][0], dp[x][0]);
                add(ndp[x][0], dp[x][1]);
            }
        }
        dp = ndp;
    }
    int sum = 0;
    for (int i = 1; i <= 200; i++) {
        add(sum, dp[i][0]);
    }
    cout << sum;
}