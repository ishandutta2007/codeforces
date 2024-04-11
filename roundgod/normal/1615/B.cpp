#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,l,r;
int sum[20][MAXN];
int main()
{
    for(int i=0;i<=18;i++)
        for(int j=1;j<=200000;j++)  
            if(j&(1<<i)) sum[i][j]=sum[i][j-1]; else sum[i][j]=sum[i][j-1]+1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        int ans=r-l+1;
        for(int i=0;i<=18;i++)
            ans=min(ans,sum[i][r]-sum[i][l-1]);
        printf("%d\n",ans);
    }
    return 0;
}