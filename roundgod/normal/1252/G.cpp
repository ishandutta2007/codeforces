#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,p;
ll l,r;
int pow_mod(int a,ll i,int m)
{
    int s=1%m;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
int calc(ll x)
{
    if(k%p==0) return p-1;
    int e=pow_mod(2,x,p-1);
    int res=pow_mod(k,e,p)-1;
    if(res<0) res+=p;
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld%lld%d",&k,&l,&r,&p);
        if(p==2)
        {
            if(k&1) puts("0"); else puts("1");
        }
        else
        {
            int g=(k&1)?2:1;
            int a=calc(r+1),b=calc(l),ans;
            if(b==0) ans=pow_mod(2,r-l+1,p);
            else ans=1LL*a*pow_mod(b,p-2,p)%p;
            int x=pow_mod(g,r-l,p);
            ans=1LL*ans*pow_mod(x,p-2,p)%p;
            printf("%d\n",ans);
        }
    }
    return 0;
}