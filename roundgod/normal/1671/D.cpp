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
        int mini=INF,maxi=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); mini=min(mini,a[i]); maxi=max(maxi,a[i]);}
        ll ans=0;
        for(int i=1;i<=n-1;i++) ans+=max(a[i+1]-a[i],a[i]-a[i+1]);
        if(a[1]==mini||a[n]==mini) ans+=mini-1; else ans+=min(2*(mini-1),min(a[1]-1,a[n]-1)); 
        if(x>=maxi)
        {
            if(a[1]==maxi||a[n]==maxi) ans+=x-maxi; else ans+=min(2*(x-maxi),min(x-a[1],x-a[n]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}