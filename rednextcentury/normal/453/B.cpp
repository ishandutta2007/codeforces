#include<bits/stdc++.h>
using namespace std;
int dp[101][(1<<16)+1];
int b[101][(1<<16)+1];
int num=(1<<16);
int factors[60];
int a[101];
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void getFactors()
{
    for (int i=1;i<=53;i++)
        for (int j=0;j<16;j++)
            if (i%primes[j]==0)
                factors[i]+=(1<<j);
}
void calc(int n)
{
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=53;j++)
        {
            for (int x=0;x<=num;x++)
            {
                if ((x&factors[j])!=factors[j])
                    continue;
                if ((dp[i-1][x-factors[j]]+abs(j-a[i])<dp[i][x] || dp[i][x]==-1) && dp[i-1][x-factors[j]]!=-1)
                    dp[i][x]=dp[i-1][x-factors[j]]+abs(j-a[i]), b[i][x]=j;
            }
        }
    }
}
vector<int> ret;
void getSol(int n)
{
    int ans=10000000,id=-1;
    for (int x=0;x<=num;x++)
    {
        if (dp[n][x]==-1)continue;
        if (dp[n][x]<ans)
            ans=dp[n][x],id=x;
    }
    for (int i=n;i>=1;i--)
    {
        ret.push_back(b[i][id]);
        id-=factors[b[i][id]];
    }
    reverse(ret.begin(),ret.end());
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    getFactors();
    calc(n);
    getSol(n);
    for (int i=0;i<n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}