#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN];
int pre[MAXN][MAXN],suf[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++)
                pre[0][i]=suf[n+1][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) pre[i][j]=pre[i-1][j];
            pre[i][p[i]]++;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++) suf[i][j]=suf[i+1][j];
            suf[i][p[i]]++;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                pre[i][j]+=pre[i][j-1];
                suf[i][j]+=suf[i][j-1];
            }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++) ans+=1LL*pre[j-1][p[i]-1]*suf[i+1][p[j]-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}