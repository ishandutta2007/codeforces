#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll m,n;
char a[MAXN][MAXM];
ll dp[MAXM][MAXM];
map<string,ll> mp;
vector<string> save;
int main()
{
    scanf("%I64d%I64d",&m,&n);
    dp[0][0]=1;
    for(ll i=1;i<=1001;i++)
        for(ll j=0;j<=i;j++)
        {
            if(j==0) dp[i][j]=dp[i-1][i-1];
            else dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
        }
    for(ll i=0;i<n;i++)
        scanf("%s",a[i]);
    save.clear();
    for(ll i=0;i<m;i++)
    {
        string s="";
        for(ll j=0;j<n;j++)
            s+=a[j][i];
        if(mp.find(s)==mp.end()) {mp[s]=1; save.push_back(s);} else mp[s]++;
    }
    ll ans=1;
    for(ll i=0;i<save.size();i++)
    {
        string s=save[i];
        ans=(ans*dp[mp[s]][0])%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}