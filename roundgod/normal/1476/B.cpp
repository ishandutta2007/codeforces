#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n-1;i++) scanf("%d",&a[i]);
        ll s=a[0],ans=0;
        for(int i=1;i<=n-1;i++)
        {
            ll need=(100LL*a[i]-1)/k+1;
            if(need>s) ans=max(ans,need-s);
            s+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}