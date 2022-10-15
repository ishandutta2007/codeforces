#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<ll> v[MAXN];
ll s;
ll dp[30][MAXN];
ll tmp[MAXN],ndp[MAXN];
ll solve(int l,int r,int d)
{
    if(l==r)
    {
        ll ans=-INF;
        for(int i=0;i<min((int)v[l].size(),k+1);i++) ans=max(ans,v[l][i]+dp[d][k-i]);
        return ans; 
    }
    int mid=(l+r)/2;
    for(int i=0;i<=k;i++) tmp[i]=dp[d][i];
    for(int i=mid+1;i<=r;i++) 
    {
        for(int j=0;j<=k;j++) 
        {
            ndp[j]=tmp[j];
            if(j>=(int)v[i].size()-1) ndp[j]=max(ndp[j],tmp[j-(int)v[i].size()+1]+v[i].back());
        }
        swap(ndp,tmp);
    }
    for(int i=0;i<=k;i++) dp[d+1][i]=tmp[i];
    ll ans=solve(l,mid,d+1);
    for(int i=0;i<=k;i++) tmp[i]=dp[d][i];
    for(int i=l;i<=mid;i++) 
    {
        for(int j=0;j<=k;j++) 
        {
            ndp[j]=tmp[j];
            if(j>=(int)v[i].size()-1) ndp[j]=max(ndp[j],tmp[j-(int)v[i].size()+1]+v[i].back());
        }
        swap(ndp,tmp);
    }
    for(int i=0;i<=k;i++) dp[d+1][i]=tmp[i];
    ans=max(ans,solve(mid+1,r,d+1));
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        v[i].push_back(0);
        int t;
        scanf("%d",&t);
        ll s=0;
        for(int j=0;j<t;j++)
        {
            int x;
            scanf("%d",&x);
            if(j<=k) {s+=x; v[i].push_back(s);}
        }
    }
    for(int i=1;i<=k;i++) dp[0][i]=-INF;
    printf("%lld\n",solve(0,n-1,0));
    return 0;
}