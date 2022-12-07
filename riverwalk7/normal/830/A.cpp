#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define MAXN 2020
using namespace std;
typedef long long ll;
int N, K; ll P;
ll a[MAXN];
ll b[MAXN];
ll DP[MAXN][MAXN];
int main()
{
    cin>>N>>K>>P;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=K; i++)
    {
        cin>>b[i];
    }
    sort(a+1, a+N+1);
    sort(b+1, b+K+1);
    for(int i=1; i<=N; i++)
    {
        DP[i][0] = 1e18;
        for(int j=1; j<=K; j++)
        {
            DP[i][j] = max(DP[i-1][j-1], abs(a[i]-b[j])+abs(b[j]-P));
            DP[i][j] = min(DP[i][j-1], DP[i][j]);
        }
    }
    cout<<DP[N][K]<<endl;
}