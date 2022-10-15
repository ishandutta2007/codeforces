#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll cal()
{
    ll k=1;
    for(ll j=30;j>=0;j--)
    {
        ll t=0;
        for(ll i=k;i<=n;i++)
        {
            if((a[i]>>j)&1)
            {
                t=i;
                break;
            }
        }
        if(t)
        {
            swap(a[t],a[k]);
            for(ll i=1;i<=n;i++)
                if(i!=k&&((a[i]>>j)&1)) a[i]^=a[k];
            k++;
        }
    }
    return k-1;
}
int main()
{
    scanf("%lld",&n);
    ll s=0;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        s^=a[i];
    }
    if(s==0) puts("-1"); else printf("%lld\n",cal());
    return 0;
}