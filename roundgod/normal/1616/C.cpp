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
        int ans=n-1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int res=n;
                for(int k=1;k<=n;k++)
                {
                    if((i-k)*(a[j]-a[i])==(j-i)*(a[i]-a[k])) res--;
                }
                ans=min(ans,res);
            }
        printf("%d\n",ans);
    }
    return 0;
}