#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],s[MAXN],dp[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
        dp[0]=0; mp[0]=0;
        int ans=0,mini=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=INF;
            dp[i]=min(dp[i],mini+i);
            if(mp.find(s[i])!=mp.end()) dp[i]=min(dp[i],mp[s[i]]+i-1);
            mini=min(mini,dp[i]-i);
            mp[s[i]]=min(s[i],dp[i]-i);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}