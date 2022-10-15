#pragma GCC optimize(3)
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
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>=2*a[1])
            {
                int need=(2*a[1]-1);
                ans+=(a[i]-1)/need;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}