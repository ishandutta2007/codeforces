#include <iostream>
#include <fstream>
#define N 5000
#define MOD 998244353
using namespace std;
typedef long long ll;
int a, b, c;
ll DP[N+1][N+1];
int main()
{
    cin>>a>>b>>c;
    for(int i=0; i<=N; i++)
    {
        DP[i][0] = DP[0][i] = 1;
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            DP[i][j] = j*DP[i-1][j-1]+DP[i-1][j];
            DP[i][j] %= MOD;
        }
    }
    ll ans = (DP[a][b] * DP[a][c]) % MOD;
    ans = (ans * DP[b][c]) % MOD;
    cout<<ans<<endl;
}