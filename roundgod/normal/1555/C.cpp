#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[2][MAXN],sum[2][MAXN];
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
        int ans=INF+1;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,max(sum[1][i-1],sum[0][n]-sum[0][i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}