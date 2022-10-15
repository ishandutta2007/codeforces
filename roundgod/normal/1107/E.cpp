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
int n,k,a[MAXN];
ll res[MAXN];
ll dp[MAXN][MAXN][MAXN];
char str[MAXN];
vector<int> v;
ll solve(int l,int r,int cnt)
{
    if(l>r) return res[cnt];
    if(dp[l][r][cnt]!=-1) return dp[l][r][cnt];
    ll &ans=dp[l][r][cnt];
    ans=max(ans,res[cnt+v[l]]+solve(l+1,r,0));
    for(int i=l+2;i<=r;i+=2)
    {
        ans=max(ans,solve(i,r,v[l]+cnt)+solve(l+1,i-1,0));
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    res[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        res[i]=a[i];
        for(int j=1;j<=i-1;j++)
            res[i]=max(res[i],res[j]+res[i-j]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&str[i]!=str[i-1])
        {
            v.push_back(cnt);
            cnt=1;
        }
        else cnt++;
    }
    v.push_back(cnt);
    int sz=(int)v.size();
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(0,sz-1,0));
    return 0;
}