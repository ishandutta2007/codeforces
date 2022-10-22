#include <iostream>
#include <iomanip>
using namespace std;

const int INF = 100000000;

int d[102][10002];
int dp[102][10002];

int main()
{
    int n;
    cin >> n;
    int a[105], b[105];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int j = 0; j <= n; j++){
        for(int s = 0; s <= 10000; s++) dp[j][s] = INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int s = 0; s <= 10000; s++) d[j][s] = dp[j][s] + b[i - 1];
        }
        for(int j = 1; j <= n; j++){
            for(int s = a[i - 1] - b[i - 1]; s <= 10000; s++){
                d[j][s] = min(d[j][s], dp[j - 1][s - (a[i - 1] - b[i - 1])]);
            }
        }
        for(int j = 0; j <= n; j++){
            for(int s = 0; s <= 10000; s++) dp[j][s] = d[j][s];
        }
    }
    int w = 0;
    for(int i = 0; i < n; i++) w += b[i];
    int ans[102]{0};
    for(int k = 1; k <= n; k++){
        for(int s = 0; s <= 10000; s++){
            ans[k] = max(ans[k], w * 2 - dp[k][s] * 2 + min(s * 2, dp[k][s]));
        }
    }
    for(int k = 1; k <= n; k++) cout << fixed << setprecision(15) << ans[k] * 1.0 / 2 << " ";
    cout << endl;
}