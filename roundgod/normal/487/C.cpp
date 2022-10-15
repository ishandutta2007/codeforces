#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int p[MAXN];
vector<ll> a;
ll pow_mod(ll a,ll i,ll mod)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%mod;
         a=(a*a)%mod;
         i>>=1;
     }
     return s;
}
bool g_test(ll g,ll p)
{
    for(ll i=0;i<a.size();i++)
        if(pow_mod(g,(p-1)/a[i],p)==1)
            return 0;
    return 1;
}
ll primitive_root(ll p)
{
    ll tmp=p-1;
    for(ll i=2;i<=tmp/i;i++)
        if(tmp%i==0)
        {
            a.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp!=1)
    {
        a.push_back(tmp);
    }
    ll g=1;
    while(true)
    {
        if(g_test(g,p))
            return g;
        ++g;
    }
}
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        puts("YES\n1");
        return 0;
    }
    else if(n==2)
    {
        puts("YES\n1\n2\n");
        return 0;
    }
    else if(n==4)
    {
        puts("YES\n1\n3\n2\n4\n");
        return 0;
    }
    else
    {
        bool f=true;
        for(int i=2;i*i<=n;i++) if(n%i==0) f=false;
        if(!f) {puts("NO"); return 0;}
        puts("YES");
        int g=primitive_root(n);
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=1LL*p[i-1]*g%n;
        printf("%d\n%d\n",1,p[1]);
        int l=1,r=n-2;
        for(int i=1;i<=n-3;i++)
        {
            int res;
            if(i&1) {res=r-l; r--;}
            else {res=l-r; l++;}
            res=(res%(n-1)+(n-1))%(n-1);
            printf("%d\n",p[res]);
        }
        printf("%d\n",n);
    }
    return 0;
}