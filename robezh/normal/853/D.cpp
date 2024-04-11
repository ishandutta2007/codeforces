#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50, INF = (int)1e9;

int n, a[N];
int dp[N][30 + 1];

void umax(int &to, int val) {
    to = max(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i], a[i] /= 100, sum += a[i];
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + 30 + 1, -INF);
    dp[n][0] = 0;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j <= 30; j++) {
            if(dp[i][j] == -INF) continue;
            if(j + a[i-1] <= 30) umax(dp[i-1][j + a[i-1]], dp[i][j]);
            if(j - a[i-1] / 10 >= 0) umax(dp[i-1][j - a[i-1] / 10], dp[i][j] + a[i-1] / 10);
        }
    }
    int mx_sv = *max_element(dp[0], dp[0] + 31);
    cout << (sum - mx_sv) * 100 << endl;

}