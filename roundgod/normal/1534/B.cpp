#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=a[n+1]=0;
        ll ans=0;
        for(int i=1;i<=n+1;i++) ans+=max(a[i]-a[i-1],a[i-1]-a[i]);
        for(int i=1;i<=n;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) ans-=min(a[i]-a[i-1],a[i]-a[i+1]);
        printf("%lld\n",ans);
    }
    return 0;
}