#include<stdio.h>
#include<cstring>
#define MAXN 1100
using namespace std;
int num[6][MAXN];int n,k;
int ct[6][MAXN];
int f[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    for(int j=1;j<=n;j++)
    {scanf("%d",&num[i][j]);ct[i][num[i][j]]=j;}
    for(int i=1;i<=n;i++)
    {
            int ii=num[1][i];f[ii]=1;
            for(int j=1;j<i;j++)
            {
                    int jj=num[1][j];
                    bool flag=1;
                    for(int p=2;p<=k;p++)
                    if(ct[p][jj]>ct[p][ii])flag=0;
                    if(!flag)continue;
                    if(f[jj]+1>f[ii])f[ii]=f[jj]+1;
                    }
                    }
    //rintf("%d\n",f[2]);
    int ans=0;
    for(int i=1;i<=n;i++)if(f[i]>ans)ans=f[i];
    printf("%d\n",ans);
    return 0;
}