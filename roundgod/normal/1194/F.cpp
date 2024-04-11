#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,t[MAXN];
ll T,sum;
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
int fact[MAXN],invf[MAXN],p[MAXN],invp[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
vector<P> v;
const int block=400;
bool cmp(P x,P y)
{
    if(x.F/block!=y.F/block) return x.F/block<y.F/block;
    if(x.F/block&1) return x.S>y.S; else return x.S<y.S;
}
int main()
{
    fact[0]=invf[0]=p[0]=invp[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=200000;i++) p[i]=2LL*p[i-1]%MOD;
    invp[200000]=pow_mod(p[200000],MOD-2);
    for(int i=199999;i>=1;i--) invp[i]=2LL*invp[i+1]%MOD;
    scanf("%d%lld",&n,&T);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=t[i];
        if(sum>T) break;
        if(sum+i<=T) {add(ans,1); continue;}
        else v.push_back(P(T-sum,i));
    }
    sort(v.begin(),v.end(),cmp);
    int l=0,r=1;
    int val=1;
    for(int i=0;i<(int)v.size();i++)
    {
        while(r<v[i].S) 
        {
            val=2LL*val%MOD;
            dec(val,comb(r,l));
            r++;
        }
        while(r>v[i].S)
        {
            r--;
            add(val,comb(r,l));
            val=1LL*val*INV%MOD;
        }
        while(l<v[i].F)
        {
            l++;
            add(val,comb(r,l));
        }
        while(l>v[i].F)
        {
            dec(val,comb(r,l));
            l--;
        }
        add(ans,1LL*val*invp[v[i].S]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}