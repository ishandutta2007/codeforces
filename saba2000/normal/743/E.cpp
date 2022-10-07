#include<bits/stdc++.h>
using namespace std;
int n, a[1009];
int L[1009][1009];
int dp[1009][4146];
int check (int x)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 256; j++)
        {
            dp[i][j] = -1000000000;
        }
    dp[0][0]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <256; j++)
        {
            int N = (j|(1<<a[i]));
            int P = (N^(1<<a[i]));
            if(L[i][x] != -1)
            {
                dp[i][N] = max( dp[i][N], x + dp[L[i][x]-1][P]);
            }
            if(L[i][x+1] != -1)
            {
                dp[i][N] = max( dp[i][N], x+1 + dp[L[i][x+1]-1][P]);
            }
        }
         for (int j = 0; j <256; j++)
        {
            dp[i][j] = max (dp[i][j], dp[i-1][j]);
        }
    }
    return dp[n][255];

}
vector< int > v[9];
main()
{
    cin>> n;
    int ans=0;
    for (int i = 1; i <= n; i++)
        {
            cin>> a[i];
            a[i]--;
            v[a[i]].push_back(i);

        }
    for (int i = 0; i < 8; i++)
    {
         if(v[i].size()) ans++;
        for (int j = 0; j < v[i].size(); j++)
        {
            for (int k = 1; k <= n+9; k++)
            {
                if(k>j+1)
                    L[v[i][j]][k] = -1;
                else
                    L[v[i][j]][k] = v[i][j-k+1];
            }
        }

    }
    int l=1,r=n-1;
    while(l < r)
    {
        int mid=(l + r + 1)/2;
        if(check (mid) > 0) l=mid;
        else r = mid -1 ;
    }
    cout << max(check(l), ans) << endl;
}