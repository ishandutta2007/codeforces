#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,m,a[MAXN];
typedef long double db;
int main()
{
    scanf("%lld%lld%lld",&n,&k,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    ll s=0;
    db ans=0;
    for(ll i=1;i<=n;i++)
    {
        s+=a[i];
        ll need=n-i;
        if(need>m) continue;
        ans=max(ans,(db)(s+min(m-need,i*k))/i);
    }
    printf("%.15Lf\n",ans);
    return 0;
}