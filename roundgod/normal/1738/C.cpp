#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN][MAXN][2][2][2],sum[MAXN];
int solve(int l,int r,int alice,int bob,int who)
{
    if(dp[l][r][alice][bob][who]!=-1) return dp[l][r][alice][bob][who];
    if(l>r)
    {
        if(alice&1) {if(who==0) return 0; else return 1;}
        else {if(who==1) return 0; else return 1;}
    }
    if(who==0)
    {
        int res=0;
        if(!solve(l+1,r,alice^a[l],bob,1)) res=1;
        if(!solve(l,r-1,alice^a[r],bob,1)) res=1;
        return dp[l][r][alice][bob][who]=res;
    }
    else
    {
        int res=0;
        if(!solve(l+1,r,alice,bob^a[l],0)) res=1;
        if(!solve(l,r-1,alice,bob^a[r],0)) res=1;
        return dp[l][r][alice][bob][who]=res;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]&1) cnt++;
        }
        if(cnt&1) {if(n&1) {if(((cnt+1)/2)%2==0)puts("Alice"); else puts("Bob");} else puts("Alice");}
        else {if(cnt%4==0) puts("Alice"); else puts("Bob");}
    }
    return 0;
}