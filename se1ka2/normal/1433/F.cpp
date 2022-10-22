#include <iostream>
#include <bitset>
using namespace std;

const int INF = 1000000000;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[73][73];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int b[100][100];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < k; j++) b[i][j] = -INF;
    }
    b[0][0] = 0;
    for(int i = 0; i < n; i++){
        int dp[100][100];
        for(int l = 0; l <= m / 2; l++){
            for(int s = 0; s < k; s++) dp[l][s] = -INF;
        }
        dp[0][0] = 0;
        for(int j = 0; j < m; j++){
            for(int l = m / 2; l > 0; l--){
                for(int s = 0; s < k; s++){
                    dp[l][s] = max(dp[l][s], dp[l - 1][(s + k * 100 - a[i][j]) % k] + a[i][j]);
                }
            }
        }
        int d[100];
        for(int s = 0; s < k; s++){
            d[s] = -INF;
            for(int l = 0; l <= m / 2; l++) d[s] = max(d[s], dp[l][s]);
        }
        for(int t = 0; t < k; t++){
            for(int s = 0; s < k; s++){
                b[i + 1][t] = max(b[i + 1][t], b[i][(t + k - s) % k] + d[s]);
            }
        }
    }
    cout << b[n][0] << endl;
}