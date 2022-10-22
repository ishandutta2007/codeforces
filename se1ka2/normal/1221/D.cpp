#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000;

ll dp[300005][3];

int main()
{
    int q;
    cin >> q;
    int a[300005];
    ll b[300005];
    for(int c = 0; c < q; c++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %lld", &a[i], &b[i]);
            for(int j = 0; j < 3; j++) dp[i][j] = INF;
        }
        dp[0][0] = 0;
        dp[0][1] = b[0];
        dp[0][2] = b[0] * 2;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(a[i - 1] + k != a[i] + j) dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
            }
        }
        printf("%lld\n", min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])));
    }
}