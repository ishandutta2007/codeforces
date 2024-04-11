#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll u,v;
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
    scanf("%lld%lld",&u,&v);
    if(u==0&&v==0)
    {
        puts("0");
        return 0;
    }
    if(u>v||(v-u)&1)
    {
        puts("-1");
        return 0;
    }
    if(u==v)
    {
        puts("1");
        printf("%lld\n",u);
        return 0;
    }
    ll x=(v-u)/2;
    if(!(x&u))
    {
        puts("2");
        printf("%lld %lld\n",x^u,x);
    }
    else
    {
        puts("3");
        printf("%lld %lld %lld\n",u,x,x);
    }
    
    return 0;
}