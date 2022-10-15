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
int t,n,x,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll s=0,ans=0;
        for(int i=1;i<=n;i++) s+=a[i];
        int day=0;
        for(int i=n;i>=1;i--)
        {
            if(s+1LL*day*i<=x)
            {
                int delta=(x-s-1LL*day*i)/i+1;
                ans+=1LL*delta*i;
                day+=delta;
            }
            s-=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}