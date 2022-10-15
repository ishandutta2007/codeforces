#include<bits/stdc++.h>
#define MAXN 100005
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
        int mini=INF;
        int maxi=-INF;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==-1&&a[i-1]==-1) continue;
            if(a[i]==-1)
            {
                mini=min(mini,a[i-1]);
                maxi=max(maxi,a[i-1]);
            }
            else if(a[i-1]==-1)
            {
                mini=min(mini,a[i]);
                maxi=max(maxi,a[i]);
            }
            else ans=max(ans,max(a[i]-a[i-1],a[i-1]-a[i]));
        }
        int k;
        if(mini<=maxi)
        {
            ans=max(ans,(maxi-mini+1)/2);
            k=(maxi+mini)/2;
        }
        else k=0;
        printf("%d %d\n",ans,k);
    }
    return 0;
}