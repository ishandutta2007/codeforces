#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int dp[100][200005];

int main()
{
    int n, m;
    cin >> n >> m;
    int x[100], s[100];
    P p[100];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> s[i];
        p[i] = P(x[i], s[i]);
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++){
        x[i] = p[i].first;
        s[i] = p[i].second;
    }
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m * 2; j++) dp[i][j] = 100000000;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = m * 2 - 1; j >= 0; j--){
            if(x[i - 1] - (j - x[i - 1]) - 1 <= 0){
                dp[i][j] = min(dp[i - 1][j], max(0, j - (x[i - 1] + s[i - 1])));
            }
            else{
                dp[i][j] = min(dp[i - 1][j],
                               dp[i - 1][x[i - 1] - (j - x[i - 1]) - 1] + max(0, j - (x[i - 1] + s[i - 1])));
            }
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    int ans = 100000000;
    for(int j = m; j <= m * 2; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
}