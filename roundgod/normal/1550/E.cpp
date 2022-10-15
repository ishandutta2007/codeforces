#include<bits/stdc++.h>
#define MAXN 200005
#define MAXK 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
char str[MAXN];
int num;
int cnt[MAXN][MAXK];
int nxt[MAXN][MAXK];
int dp[(1<<17)];
bool check(int x)
{
    for(int i=0;i<k;i++) nxt[n+1][i]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<k;j++)
        {
            if(i+x-1<=n&&cnt[i+x-1][k]-cnt[i-1][k]+cnt[i+x-1][j]-cnt[i-1][j]==x) nxt[i][j]=i;
            else nxt[i][j]=nxt[i+1][j];
        }
    }
    for(int i=0;i<(1<<k);i++) dp[i]=n+1;
    dp[0]=0;
    for(int i=0;i<(1<<k);i++)
    {
        if(dp[i]==n+1) continue;
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j)) continue;
            dp[i^(1<<j)]=min(dp[i^(1<<j)],min(n+1,nxt[dp[i]+1][j]+x-1));
        }
    }
    return dp[(1<<k)-1]<=n;
}
set<int> s;
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++) cnt[i][j]=cnt[i-1][j];
        if(str[i]=='?') cnt[i][k]++;
        else cnt[i][str[i]-'a']++;
    }
    num=(int)s.size();
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
    return 0;
}