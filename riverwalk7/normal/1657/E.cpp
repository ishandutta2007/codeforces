#include <iostream>
#include <fstream>
#define MAXN 253
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int N, K;
ll power[MAXN][MAXN];
ll DP[MAXN][MAXN][MAXN];
ll sum[MAXN][MAXN];
ll inv[MAXN];
ll ans;
int main()
{
    cin>>N>>K;
    for(ll i=1; i<=K; i++)
    {
        power[i][0] = 1;
        for(ll j=1; j<=N; j++)
        {
            power[i][j] = power[i][j-1]*i%MOD;
        }
    }
    inv[1] = 1;
    for(ll i=2; i<=N; i++)
    {
        inv[i] = (MOD-inv[MOD%i])*(MOD/i)%MOD;
    }
    for(int i=1; i < N; i++) //i = number of vertices added so far
    {
        for(int j=K; j >= 1; j--) //j = current weight of edge added
        {
            for(int k=1; k < N; k++) //k = number of edges with this weight
            {
                if(k == 1)
                {
                    for(int l=j+1; l<=K; l++)
                    {
                        DP[i][j][k] += sum[i-1][l];
                    }
                    DP[i][j][k] %= MOD;
                    if(i == 1)
                    {
                        DP[i][j][k] = 1;
                    }
                    DP[i][j][k] *= power[K-j+1][N-i-1];
                    DP[i][j][k] %= MOD;
                }
                else
                {
                    DP[i][j][k] = DP[i-1][j][k-1]*power[K-j+1][N-i-1];
                    DP[i][j][k] %= MOD;
                    DP[i][j][k] *= inv[k];
                    DP[i][j][k] %= MOD;
                }
                sum[i][j] += DP[i][j][k];
                sum[i][j] %= MOD;
            }
        }
    }
    for(int j=1; j<=K; j++)
    {
        for(int k=1; k<=N; k++)
        {
            ans += DP[N-1][j][k];
            ans %= MOD;
        }
    }
    for(int i=1; i<N; i++)
    {
        ans *= i;
        ans %= MOD;
    }
    cout<<ans<<endl;
}