#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000000000001LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n;
ll a[MAXN];
vector<int> v;
vector<int> tmp1,tmp2;
int sum[65][MAXN];
ll dp[65][MAXN];
void relax(ll &a,ll b) {a=min(a,b);} 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) a[i]=a[n]-a[i];
    for(int i=1;i<=n;i++) v.push_back(i);
    for(int i=0;i<=62;i++)
    {
        tmp1.clear(); tmp2.clear();
        sum[i][0]=0;
        for(int j=0;j<(int)v.size();j++) 
            if((a[v[j]]>>i)&1) 
            {
                sum[i][j+1]=sum[i][j]+1;
                tmp2.push_back(v[j]); 
            }
            else 
            {
                sum[i][j+1]=sum[i][j];
                tmp1.push_back(v[j]);
            }
        v.clear();
        v.insert(v.end(),tmp1.begin(),tmp1.end());
        v.insert(v.end(),tmp2.begin(),tmp2.end());
    }
    for(int i=0;i<=64;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][n]=0;
    for(int i=0;i<64;i++)
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j]==INF) continue;
            int carry=(sum[i][n]-sum[i][j]);
            int res=sum[i][j]+(n-j-(sum[i][n]-sum[i][j]));
            relax(dp[i+1][n-carry],dp[i][j]+res);
            carry=(sum[i][j]+(n-j));
            res=(j-sum[i][j])+(sum[i][n]-sum[i][j]);
            relax(dp[i+1][n-carry],dp[i][j]+res);
        }
    ll ans=INF;
    for(int i=0;i<=n;i++) ans=min(ans,dp[64][i]+(n-i));
    printf("%lld\n",ans);
    return 0;
}