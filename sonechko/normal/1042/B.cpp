#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 11;

int a[N],dp[2][2][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    for (int aaa=0; aaa<=1; aaa++)
    for (int bbb=0; bbb<=1; bbb++)
    for (int ccc=0; ccc<=1; ccc++)
        dp[aaa][bbb][ccc]=1e8;
    for (int i=1; i<=n; i++)
    {
        int c;
        string s;
        cin>>c>>s;
        int aa=0,bb=0,cc=0;
        for (int j=0; j<s.size(); j++)
            if (s[j]=='A') aa=1; else
            if (s[j]=='B') bb=1; else
            if (s[j]=='C') cc=1;
        for (int aaa=0; aaa<=aa; aaa++)
        for (int bbb=0; bbb<=bb; bbb++)
        for (int ccc=0; ccc<=cc; ccc++)
        {
            dp[aaa][bbb][ccc]=min(dp[aaa][bbb][ccc],c);
        }
    }
    int ans=1e8;
    ans=min(ans,dp[1][0][0]+dp[0][1][0]+dp[0][0][1]);
    ans=min(ans,dp[1][0][0]+dp[0][1][1]);
    ans=min(ans,dp[0][1][0]+dp[1][0][1]);
    ans=min(ans,dp[0][0][1]+dp[1][1][0]);
    ans=min(ans,dp[1][1][1]);
    if (ans==100000000) cout<<-1; else cout<<ans;

}