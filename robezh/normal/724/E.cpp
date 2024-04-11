#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10005;
const ll INF = (ll)1e18;

int n, c;
int p[N], s[N];
ll dp[2][N];

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    int now = 1, la = 0;
    fill(dp[now], dp[now] + N, INF);
    dp[now][0] = 0;
    for(int i = 0; i < n; i++) {
       swap(now, la);
       fill(dp[now], dp[now] + N, INF);
       for(int j = 0; j <= n; j++) {
           dp[now][j] = dp[la][j] + s[i];
           if(j >= 1) dp[now][j] = min(dp[now][j], dp[la][j-1] + p[i] + 1LL * (i - j + 1) * c);
       }
    }
    ll res = INF;
    for(int i = 0; i <= n; i++) res = min(res, dp[now][i]);
    cout << res << endl;


}