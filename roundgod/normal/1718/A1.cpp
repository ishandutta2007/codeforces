#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],s[MAXN],dp[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
        dp[0]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=INF;
            for(int j=0;j<i;j++) dp[i]=min(dp[i],dp[j]+i-j-(s[i]==s[j]?1:0));
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}