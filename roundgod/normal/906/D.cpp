#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,w[MAXN];
unordered_map<int,int> phi;
int f(ll x,int m) {return x<m?x:x%m+m;}
int pow_mod(int a,int i,int m)
{
    int s=1%m;
    while(i)
    {
        if(i&1) s=f(1LL*s*a,m);
        a=f(1LL*a*a,m);
        i>>=1;
    }
    return s;
}
int getphi(int n)
{
    if(phi.find(n)!=phi.end()) return phi[n];
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return phi[n]=res;
}
int solve(int l,int r,int m)
{
    if(m==1||l>r||w[l]==1) return 1;
    return pow_mod(f(w[l],m),solve(l+1,r,getphi(m)),m);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",solve(l,r,m)%m);
    }
    return 0;
}