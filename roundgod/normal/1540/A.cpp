#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int d[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        sort(d+1,d+n+1);
        ll ans=d[n];
        ll sum=0;
        for(int i=2;i<=n;i++)
        {
            ans-=1LL*(i-1)*d[i]-sum;
            sum+=d[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}