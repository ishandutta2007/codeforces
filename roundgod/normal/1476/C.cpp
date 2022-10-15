#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c[MAXN],a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        ll ans=0;
        ll res=max(a[2]-b[2],b[2]-a[2]);
        for(int i=2;i<=n-1;i++) 
        {
            res+=2;
            ans=max(ans,res+c[i]-1);
            if(a[i+1]==b[i+1]) res=0;
            else 
            {
                res=res+c[i]-1-max(a[i+1],b[i+1])+min(a[i+1],b[i+1]);
                res=max(res,1LL*(max(a[i+1],b[i+1])-min(a[i+1],b[i+1])));
            }
        }
        ans=max(ans,res+c[n]+1);
        printf("%lld\n",ans);
    }
    return 0;
}