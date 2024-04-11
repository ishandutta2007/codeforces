#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x[MAXN],y[MAXN];
int fact[MAXN],invf[MAXN];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
//C(2n-comp-1,n)
vector<P> op;
int t,pos[MAXN];
int main()
{
    scanf("%d",&t);
    op.clear();
    fact[0]=invf[0]=1;
    for(int i=1;i<=400000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[400000]=pow_mod(fact[400000],MOD-2);
    for(int i=399999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    while(t--)
    {
        op.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=m-1;i>=0;i--)
        {
            //find correct rank
            int l=0,r=n;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(sum(mid)+y[i]<=mid) r=mid; else l=mid;
            }
            pos[i]=r;
            add(pos[i],1);
            op.push_back(P(pos[i],i));
        }
        int bar=(int)op.size();
        sort(op.begin(),op.end());
        for(int i=0;i<(int)op.size()-1;i++)
            if(op[i].F==op[i+1].F-1&&op[i].S<op[i+1].S) bar--;
        printf("%d\n",comb(2*n-bar-1,n));
        for(auto x:op) add(x.F,-1);
    }
    return 0;
}