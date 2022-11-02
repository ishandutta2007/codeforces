#include<cstdio>

#define N 5010
#define mo 1000000007
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

int n,now,f[N][N],sum[N][N],Same[N][N],a[N];

int main()
{
    scanf("%d",&n);
    char ch=getchar();
    ch=getchar();
    for(int i=1;i<=n;i++)
        a[i]=ch-'0',ch=getchar();
    for(int i=n;i;i--)
        for(int j=n;j;j--)
            if(a[i]!=a[j])Same[i][j]=0;
            else Same[i][j]=Same[i+1][j+1]+1;
    for(int i=1;i<=n;i++)
    {
        if(a[1]!='0')f[i][i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[i-j+1]==0)continue; 
            if(j<=i-j)
            {
                f[i][j]+=sum[i-j][j-1];
                if(f[i][j]>=mo)f[i][j]-=mo;
                now=Same[i-2*j+1][i-j+1];
                if(now>=j||a[i-2*j+now+1]>=a[i-j+now+1])continue;
                f[i][j]+=f[i-j][j];
                if(f[i][j]>=mo)f[i][j]-=mo;
            }
            else
            {
                f[i][j]+=sum[i-j][i-j];
                if(f[i][j]>=mo)f[i][j]-=mo;
            }
        }
        for(int j=1;j<=i;j++)
        {
            sum[i][j]=sum[i][j-1]+f[i][j];
            if(sum[i][j]>=mo)sum[i][j]-=mo;
        }
    }
    printf("%d\n",sum[n][n]);
}