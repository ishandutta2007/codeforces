#include <bits/stdc++.h>
using namespace std;
long long dp1[2002][2002];
#define MOD 1000000007
int main()
{
    dp1[0][0]=1;
    for (int i=0;i<2000;i++)
    {
        for (int j=0;j<=2000;j++)
        {
            if (j>0)
                dp1[i+1][j-1]+=dp1[i][j],dp1[i+1][j-1]%=MOD;
            dp1[i+1][j+1]+=dp1[i][j],dp1[i+1][j+1]%=MOD;
        }
    }
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    long long val=0;
    long long mn=0;
    for (int i=0;i<m;i++)
    {
        if (s[i]=='(')val++;
        else val--;
        mn=min(mn,val);
    }
    int len=n-m;
    int ans=0;
    for (int i=0;i<=len;i++)
    {
        for (int j=-mn;j<=2000;j++)
        {
            if (j+val>=0 && j+val<=2000)
                ans+=(dp1[i][j]*dp1[len-i][j+val])%MOD,ans%=MOD;
        }
    }
    cout<<ans<<endl;
}