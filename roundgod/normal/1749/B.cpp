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
int t,n,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll ans=0;
        int maxi=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); ans+=a[i];}
        for(int i=1;i<=n;i++) {scanf("%d",&b[i]); ans+=b[i]; maxi=max(maxi,b[i]);}
        ans-=maxi;
        printf("%lld\n",ans);
    }
    return 0;
}