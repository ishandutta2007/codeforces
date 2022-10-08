#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000LL
ll ff(ll a,ll b,ll c)
{
    /*
        a+y=x+z
        b+z=x+y
        c+x-y-z max
    */
    if((a+b)%2!=0)return INF;
    ll x=(a+b)/2;
    if(a<b)swap(a,b);
    ll y=0,z=(a-b)/2;
    return x+y+z;
}
int main()
{
    ll a,b,c;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    printf("%I64d\n",min(min(ff(a,b,c),ff(b,c,a)),ff(c,a,b)));
    return 0;
}