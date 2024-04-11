#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,a,b,c,d;
ll calc(ll tt)
{
    if(tt==0) return a;
    ll st=a-b*(1LL*tt*d),ed=a;
    return 1LL*(st+ed)*(tt+1)/2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(1LL*b*c<a) puts("-1");
        else 
        {
            ll ltime=(a+b-1)/b;
            ll round=(ltime-1)/d;
            printf("%lld\n",calc(round));
        }
        
    }
}