#include <iostream>
#include <fstream>
#define MAXN 2020
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int T;
int N, M, K;
ll DP[MAXN][MAXN]; //optimal score if Bob adds j of the remaining i turns and Alice goes next
ll solve()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(j == i)
            {
                DP[i][j] = (DP[i-1][j-1] + K) % MOD;
            }
            else
            {
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j]) * (MOD+1)/2 % MOD;
            }
        }
    }
    return DP[N][M];
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>M>>K;
        cout<<solve()<<endl;
    }
}