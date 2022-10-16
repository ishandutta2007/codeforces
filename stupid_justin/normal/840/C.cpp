#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=3.3e4;
const int M=305;
const int mod=1e9+7;
int prim[N],vis[N],cnt;
int a[N],n;
int sz[N],num[N],m,sum;
int C[M][M],g[M][M],dp[M][M];
void init()
{
    for (int i=2;i<N;i++)
    {
        if (!vis[i]) prim[++cnt]=i;
        for (int j=1;j<=cnt;j++)
        {
            if (i*prim[j]>=N) break;
            vis[i*prim[j]]=1;
            if (i%prim[j]==0) break;
        }
    }
    for (int i=1;i<=cnt;i++) prim[i]*=prim[i];
    for (int i=1;i<=n;i++)  for (int j=1;j<=cnt;j++) while (a[i]%prim[j]==0) a[i]/=prim[j];
    for (int i=1;i<=n;i++)
    {
        bool flag=0;
        for (int j=1;j<=n;j++)  if (a[i]==num[j]) 
        {
            sz[j]++;
            flag=1;
            break;
        }
        if (!flag) sz[++m]=1,num[m]=a[i];
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=i;j++) 
    {
        if (j==0) C[i][j]=1;
        else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    init();
    g[0][0]=dp[0][0]=1 ; 
    for (int i=1;i<=n;i++) for (int j=1;j<=i;j++) g[i][j]=(g[i-1][j]*(i+j-1)%mod+(j*g[i-1][j-1])%mod)%mod;
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<=sum;j++) 
            for (int k=1;k<=sz[i];k++) 
                for (int z=0;z<=j;z++)
                {
                    int tmp=dp[i-1][j]*g[sz[i]][k];tmp%=mod;
                    tmp*=C[j][z];tmp%=mod;
                    tmp*=C[sum+1-j][k-z];tmp%=mod;
                    dp[i][j+sz[i]-k-z]+=tmp;
                    dp[i][j+sz[i]-k-z]%=mod;
                }
        sum+=sz[i];
    }
	printf("%lld\n",dp[m][0]);
}