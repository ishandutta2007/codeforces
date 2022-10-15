#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int T,n,m;
int a[105][105];
int dp[105][105];
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<m;i++)
        {
            for(int mask=0;mask<(1<<n);mask++)
            {
                if(dp[i][mask]==-1) continue;
                for(int chosen=0;chosen<(1<<n);chosen++)
                {
                    if(chosen&mask) continue;
                    for(int shift=0;shift<n;shift++)
                    {
                        int x=dp[i][mask];
                        for(int j=0;j<n;j++)
                        {
                            if(!(chosen&(1<<j))) continue;
                            int pos=(j+shift)%n;
                            x+=a[pos][i];
                        }
                        upd(dp[i+1][chosen|mask],x);
                    }
                }
            }
        }
        printf("%d\n",dp[m][(1<<n)-1]);
    }
    return 0;
}