#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
int dp[MAXN][2];//0: same 1: not same
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=1;
    dp[0][0]=0; dp[0][1]=1;
    dp[1][0]=k-1;dp[1][1]=k-2;
    for(int i=2;i<=n;i++) 
    {
        add(dp[i][0],1LL*(k-1)*dp[i-1][1]%MOD);
        add(dp[i][1],dp[i-1][0]);
        add(dp[i][1],1LL*(k-2)*dp[i-1][1]%MOD);
    }
    int last=-1;
    for(int i=1;i<=n;i+=2)
    {
        if(a[i]!=-1)
        {
            if(last==-1)
            {
                ans=1LL*ans*pow_mod(k-1,(i-last)/2-1)%MOD;
            }
            else ans=1LL*ans*dp[(i-last)/2-1][(a[i]==a[last]?0:1)]%MOD;
            last=i;
        }
    }
    int lastid=(n&1)?n+2:n+1;
    if(last!=-1) ans=1LL*ans*pow_mod(k-1,(lastid-last)/2-1)%MOD;
    else 
    {
        ans=1LL*ans*k%MOD;
        ans=1LL*ans*pow_mod(k-1,(lastid-last)/2-2)%MOD;
    }
    last=0;
    for(int i=2;i<=n;i+=2)
    {
        if(a[i]!=-1)
        {
            if(last==0)
            {
                ans=1LL*ans*pow_mod(k-1,(i-last)/2-1)%MOD;
            }
            else ans=1LL*ans*dp[(i-last)/2-1][(a[i]==a[last]?0:1)]%MOD;
            last=i;
        }
    }
    lastid=(n&1)?n+1:n+2;
    if(last!=0) ans=1LL*ans*pow_mod(k-1,(lastid-last)/2-1)%MOD;
    else 
    {
        ans=1LL*ans*k%MOD;
        ans=1LL*ans*pow_mod(k-1,(lastid-last)/2-2)%MOD;
    }
    printf("%d\n",ans);
    return 0;
}