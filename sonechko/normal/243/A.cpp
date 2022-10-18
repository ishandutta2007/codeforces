#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int dp[22][N],p[4000000],a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=0; j<=20; j++)
        dp[j][n+1]=-1;
    for (int i=n; i>=1; i--)
    {
        for (int j=0; j<=20; j++)
            if ((a[i]&(1<<j))>0) dp[j][i]=i; else dp[j][i]=dp[j][i+1];
    }
    for (int l=1; l<=n; l++)
    {
        int x=a[l],r=l;
        while (1==1)
        {
            p[x]=1;
            int ps=-1;
            for (int j=0; j<=20; j++)
            {
                int k=dp[j][l];
                if (dp[j][l]>r)
                {
                    if (ps==-1) ps=j; else
                    if (k<dp[ps][l]) ps=j;
                }
            }
            if (ps==-1) break;
            r=dp[ps][l];
            x=x|(a[r]);
        }
    }

    int ans=0;
    for (int i=0; i<=3000000; i++)
        {
            if (p[i]==1) ans++;
        }
    cout<<ans<<endl;
}