#include <bits/stdc++.h>
using namespace std;

const int N = 2005, INF = (int)1e9 + 50;

int n, pn;
string s, p;
int dp[N][N];
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> p;
    n = s.length();
    pn = p.length();
    s = " " + s;
    p = " " + p;
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + N, INF);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        int cur = i;
        for(int j = pn; j >= 1; j--) {
            while(cur >= 1 && s[cur] != p[j]) cur--;
            cur--;
        }
//        cout << i << ", " << cur << endl;
        for(int k = 0; k <= n; k++) {
            dp[i][k] = dp[i-1][k];
            if(k >= 1 && cur >= 0) dp[i][k] = min(dp[i][k], dp[cur][k-1] + (i - cur - pn));
        }
    }

    for(int k = 0; k <= n; k++) {
//        cout << k << ": " << dp[n][k] << endl;
        if(dp[n][k] != INF) ans[dp[n][k]] = k;
    }
    for(int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i-1]);
    for(int i = 0; i <= n; i++) cout << min(ans[i], (n - i) / pn) << " ";

}