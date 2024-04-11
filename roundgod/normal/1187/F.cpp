#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,l[MAXN],r[MAXN];
int pr[MAXN];
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    pr[1]=1;
    int ans=1;
    int sum=1;
    for(int i=2;i<=n;i++)
    {
        int lb=max(l[i-1],l[i]),rb=min(r[i-1],r[i]);
        int len=max(0,rb-lb+1);
        int d=1LL*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%MOD;
        pr[i]=1LL*len*pow_mod(d,MOD-2)%MOD;
        pr[i]=(MOD-pr[i]+1)%MOD;
        add(ans,2LL*sum*pr[i]%MOD);
        dec(ans,2LL*pr[i]*pr[i-1]%MOD);
        add(ans,pr[i]);
        add(sum,pr[i]);
    }
    if(n>=2) add(ans,2LL*pr[2]%MOD);
    for(int i=3;i<=n;i++)
    {
        int lb=max(max(l[i-1],l[i]),l[i-2]),rb=min(min(r[i-1],r[i]),r[i-2]);
        int len=max(0,rb-lb+1);
        int d=1LL*(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%MOD*(r[i-2]-l[i-2]+1)%MOD;
        int p=1LL*len*pow_mod(d,MOD-2)%MOD;
        int sp=(MOD+1-pr[i-1])%MOD;
        add(sp,(MOD+1-pr[i])%MOD);
        dec(sp,p);
        sp=(MOD+1-sp)%MOD;
        add(ans,2LL*sp%MOD);
    }
    printf("%d\n",ans);
    return 0;
}