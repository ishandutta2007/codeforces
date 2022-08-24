#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 510;

int N, M, B;
ll MOD;
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> B >> MOD;
    
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        
        for (int j = 0; j < M; j++)
            for (int k = 0; k <= B - a; k++)
                if (dp[j][k])
                    dp[j+1][k+a] = (dp[j+1][k+a] + dp[j][k]) % MOD;
    }
    
    ll ans = 0;
    for (int i = 0; i <= B; i++)
        ans = (ans + dp[M][i]) % MOD;
    cout << ans << "\n";
    
    return 0;
}