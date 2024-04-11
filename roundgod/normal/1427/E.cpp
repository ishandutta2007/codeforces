#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k,a[MAXN],x;
vector<pair<P,int> > v;
void add(ll x,ll y)
{
    v.push_back(make_pair(P(x,y),0));
}
void xr(ll x,ll y)
{
    v.push_back(make_pair(P(x,y),1));
}
void print()
{
    printf("%d\n",(int)v.size());
    for(auto x:v)
    {
        if(x.S==0) printf("%lld + %lld\n",x.F.F,x.F.S);
        else printf("%lld ^ %lld\n",x.F.F,x.F.S);
    }
}
int main()
{
    scanf("%d",&x);
    int y;
    if(x%4==3)
    {
        add(x,x);
        xr(x,x<<1);
        y=x^(x<<1);
    }
    else y=x;
    int p=31-__builtin_clz(y);
    ll tmp=y;
    for(int i=0;i<p;i++)
    {
        add(tmp,tmp);
        tmp<<=1;
    }
    ll l=(tmp^y),r=(tmp+y);
    assert(l^r==(1<<(p+1)));
    add(tmp,y); xr(tmp,y);
    xr(l,r);
    ll m=-1;
    for(int i=1;i<=x;i++) if((1LL*i*(1<<(p+1))+1)%x==0) {m=i; break;}
    assert(m!=-1);
    ll cur=(1LL<<(p+1));
    tmp=m;
    for(int i=0;(1LL<<i)<tmp;i++)
    {
        add(1LL*(1LL<<i)*cur,1LL*(1LL<<i)*cur);
    }
    ll s=0;
    for(int i=0;(1LL<<i)<=tmp;i++)
    {
        if(tmp&(1LL<<i))
        {
            if(s!=0) add(s,1LL*(1<<i)*cur);
            s+=1LL*(1LL<<i)*cur;
        }
    }
    cur=x,tmp=(1LL*m*(1<<(p+1))+1)/x;
    for(int i=0;(1LL<<i)<tmp;i++)
    {
        add(1LL*(1<<i)*cur,1LL*(1<<i)*cur);
    }
    s=0;
    for(int i=0;(1LL<<i)<=tmp;i++)
    {
        if(tmp&(1LL<<i))
        {
            if(s!=0) add(s,1LL*(1<<i)*cur);
            s+=1LL*(1LL<<i)*cur;
        }
    }
    xr(1LL*m*(1LL<<(p+1))+1,1LL*m*(1LL<<(p+1)));
    print();
    return 0;
}