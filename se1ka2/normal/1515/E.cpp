#include <iostream>
using namespace std;
typedef long long ll;

ll p[404];
ll com[404][404];
ll dp[404][404];

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    p[0] = 0;
    p[1] = 1;
    for(int i = 2; i <= n; i++) p[i] = p[i - 1] * 2 % m;
    for(int i = 0; i <= n; i++){
        com[i][0] = 1;
        for(int j = 1; j <= i; j++) com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % m;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n + 1; i++){
        ll d[404][404];
        for(int j = 0; j <= n + 1; j++){
            for(int k = 0; k <= n + 1; k++) d[j][k] = 0;
        }
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++) d[j][k] = dp[j][k];
        }
        for(int j = 1; j <= i; j++){
            for(int k = 0; k < i; k++){
                d[j][i] = (d[j][i] + dp[j - 1][k] * com[i - j][i - 1 - k] % m * p[i - 1 - k]) % m;
            }
        }
        swap(d, dp);
    }
    ll ans = 0;
    for(int j = 0; j <= n; j++) ans = (ans + dp[j][n + 1]) % m;
    cout << ans << endl;
}