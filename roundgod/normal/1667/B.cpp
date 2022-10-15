#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll s[MAXN];
int dp[MAXN];
vector<ll> dis;
int bit[MAXN+1];
int query(int i)
{
    int s=-INF;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void update(int i,int x)
{
    while(i<=n+2)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dis.clear();
        s[0]=0;
        for(int i=1;i<=n;i++) {s[i]=s[i-1]+a[i]; dis.push_back(s[i]);}
        dis.push_back(0);
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n+2;i++) bit[i]=-INF;
        for(int i=0;i<=n;i++)
        {
            int id=lower_bound(dis.begin(),dis.end(),s[i])-dis.begin()+1;
            s[i]=id;
        }
        update(n+2-s[n],n+1);
        dp[n+1]=0;
        for(int i=n;i>=1;i--)
        {
            dp[i]=-n;
            dp[i]=max(dp[i],query(n+1-s[i-1])-i);
            dp[i]=max(dp[i],dp[i+1]+(a[i]>0?1:(a[i]<0?-1:0)));
            update(n+2-s[i-1],i+dp[i]);
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}