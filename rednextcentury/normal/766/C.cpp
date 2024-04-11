#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool can[1001][1001];
int a[1000];
int dp[1000000];
int len[1000000];
long long num[1000000];
#define MOD 1000000007
int main()
{
    fast
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="$"+s;
    for (int i=0;i<26;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        bool valid=1;
        int mn=100000000;
        for (int j=i;j<=n;j++)
        {
            mn=min(mn,a[s[j]-'a']);
            valid=valid&(mn>=(j-i+1));
            can[i][j]=valid;
        }
    }
    dp[0]=0;
    len[0]=0;
    num[0]=1;
    for (int i=1;i<=n;i++)
    {
        dp[i]=1000000;
        len[i]=0;
        for (int j=i;j>=1;j--)
        {
            if (can[j][i]){
                dp[i]=min(dp[i],dp[j-1]+1);
                if (dp[j-1]<1000000)
                    len[i]=max(len[i],max(i-j+1,len[j-1])),num[i]+=num[j-1],num[i]%=MOD;

            }
        }
    }
    cout<<num[n]<<endl<<len[n]<<endl<<dp[n]<<endl;
}