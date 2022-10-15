#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll k,d;
int maxi,mini;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cur=a[1];
        ll ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<cur)
            {
                ans+=cur-a[i];
                cur=a[i];
            }
            else cur=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}