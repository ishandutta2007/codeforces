#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
char dp[1009][2009];
main()
{
    cin >> n >> k;
    cin >> s;
    dp[0][k]='?';
    for (int i =0; i < n; i ++)
    {
        for (int j = 1; j < 2*k; j++)
        {
            if(dp[i][j] && (s[i]=='W' || s[i]=='?')) dp[i+1][j+1] = 'W';
            if(dp[i][j] && (s[i]=='D' || s[i]=='?')) dp[i+1][j] = 'D';
            if(dp[i][j] && (s[i]=='L' || s[i]=='?')) dp[i+1][j-1] = 'L';
        }
    }
    if(!dp[n][2*k] && !dp[n][0])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int x = 2*k;
    if(dp[n][0]) x=0;
    string ans="";
    for (int i = n; i >=1; i--)
    {
        ans = dp[i][x] + ans;
        if(dp[i][x]=='W') x--; else
        if(dp[i][x]=='L') x++;
    }
    cout << ans << endl;
}