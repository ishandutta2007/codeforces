#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,q;
int sum[205*205];
ll solve(ll x)
{
    return x/(a*b)*sum[a*b]+sum[x%(a*b)];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&q);
        for(int i=1;i<=a*b;i++)
        {
            if((i%a)%b!=(i%b)%a) sum[i]=1; else sum[i]=0;
            sum[i]+=sum[i-1];
        }
        for(int i=0;i<q;i++)
        {
            ll l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",solve(r)-solve(l-1));
        }
    }
    return 0;
}