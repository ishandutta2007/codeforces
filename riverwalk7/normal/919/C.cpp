#include <iostream>
#include <fstream>
#define maxn 2100
using namespace std;
int n, m, k, ans;
char grid[maxn][maxn];
int prefix[maxn][maxn][2];
int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>grid[n][m];
            prefix[i][j][0] = prefix[i-1][j][0];
            prefix[i][j][1] = prefix[i][j-1][1];
            if(grid[n][m]=='.')
            {
                prefix[i][j][0]++;
                prefix[i][j][1]++;
                if(k==1)
                {
                    ++ans;
                }
            }
        }
    }
    if(k==1)
    {
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i>=k&&(prefix[i][j][0]-prefix[i-k][j][0])==k)
            {
                ans++;
            }
            if(j>=k&&(prefix[i][j][1]-prefix[i][j-k][1])==k)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}