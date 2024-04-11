#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k[MAXN],h[MAXN],need[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&k[i]);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        need[n]=h[n];
        for(int i=n-1;i>=1;i--) need[i]=max(h[i],need[i+1]-(k[i+1]-k[i]));
        int now=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(k[i]-k[i-1]>=need[i])
            {
                ans+=1LL*(need[i]+1)*(need[i])/2;
                now=need[i];
            }
            else
            {
                int st=now+1,ed=now+(k[i]-k[i-1]);
                ans+=1LL*(st+ed)*(ed-st+1)/2;
                now=ed;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}