#include <bits/stdc++.h>
#define sz              size()
#define pb              push_back
#define Fr              first
#define Sc              second
#define int             ll
using namespace std;
typedef long long ll;
int n;
int dp[2005][2005];
int A[200200];
int r, l, h, ans;

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> h >> l >> r;
    for(int i = 1 ; i <= n ; i++) cin >> A[i];
    for (int i=0;i<=n;i++) for (int j=0;j<h;j++) dp[i][j]=-1e15;
    dp[0][0]=0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < h ; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][(j + h - A[i]) % h] + (j<=r && j>=l));
            dp[i][j] = max(dp[i][j], dp[i - 1][(j + h - A[i] + 1) % h]+ (j<=r && j>=l));
        }
        //for(int j = l ; j <= r ; j++) dp[i][j]++;
    }
    for(int i = 0 ; i < h ; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;

}