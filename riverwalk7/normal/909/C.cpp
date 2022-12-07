#include <iostream>
#include <fstream>
#define MAXN 5050
#define MOD 1000000007
using namespace std;
int N;
int DP[MAXN][MAXN];
int ans;
char a[MAXN];
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        if(i==1)
        {
            DP[i][0] = 1;
        }
        else if(a[i-1] == 'f')
        {
            for(int j=1; j<MAXN; j++)
            {
                DP[i][j] = DP[i-1][j-1];
            }
        }
        else
        {
            for(int j=MAXN-2; j>=0; j--)
            {
                DP[i][j] = DP[i-1][j] + DP[i][j+1];
                DP[i][j] %= MOD;
            }
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        ans += DP[N][i];
        ans %= MOD;
    }
    cout<<ans<<endl;
}