#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll ans=n;
        ll x=1;
        for(int i=1;i<=50;i++)
        {
            ll g=__gcd(1LL*i,x);
            x=x/g*i;
            if(x>n) break;
            ans+=n/x;
        }
        printf("%lld\n",ans%MOD);
    }
    return 0;
}