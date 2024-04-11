#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 205;
const ld INF = (ld)2e18;

int n, m;
ll k;
int num[N];
int pri[N];
ld dp[N][N];

ld calc() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n + m - 1; i++) {
        for(int j = 0; j <= n + m - 1; j++) {
            if(j >= 1 && num[i] != 1) dp[i][j] += dp[i-1][j-1];
            if(num[i] != -1) dp[i][j] += dp[i-1][j+1];
        }
    }
    return dp[n + m - 1][0];
}

int main() {
    memset(pri, 0x3f, sizeof(pri));
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int p; cin >> p;
            pri[i + j + 1] = min(pri[i + j + 1], p);
        }
    }
    int len = n + m - 1;
    for(int i = 1; i <= len; i++) {
        int mn = -1;
        for(int j = 1; j <= len; j++) {
            if(num[j] == 0 && (mn == -1 || pri[mn] > pri[j])) mn = j;
        }
        num[mn] = -1;
        ld cur_tot = calc();
        if(cur_tot < k) {
            k -= (ll)cur_tot;
            num[mn] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << (num[i + j + 1] == -1 ? '(' : ')');
        cout << endl;
    }

}