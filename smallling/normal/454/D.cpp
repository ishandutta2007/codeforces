#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int c[17],f[101][1<<16],ans[101][1<<16],a[101],n,sum[60],bo,o,now,minans,A[101];

inline void work()
{
    for(int i=2;i<59;i++)
    {
        bo=1;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                bo=0;
                break;
            }
        if(bo)c[++o]=i;
    }
}

int main()
{
    work();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<59;i++)
        for(int j=1;j<=o;j++)
            if(i%c[j]==0)sum[i]^=1<<j-1;
    memset(f,0x7f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<1<<o;j++)
            for(int k=1;k<59;k++)
                if((j&sum[k])==sum[k])
                {
                    now=f[i-1][j^sum[k]]+abs(a[i]-k);
                    if(now<f[i][j])
                    {
                        f[i][j]=now;
                        ans[i][j]=k;
                    }
                }
    minans=0x7f7f7f7f;
    for(int i=0;i<1<<o;i++)
    {
        if(f[n][i]<minans)
        {
            minans=f[n][i];
            now=i;
        }
    }
    for(int i=n;i;i--)
    {
        A[i]=ans[i][now];
        now^=sum[A[i]];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",A[i]);
}