#include<stdio.h>
#include<cstring>
using namespace std;
int f[105][65540];
int pre[105][65540];
int lj[105][65540];
int zs[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int a[105];
int n;
#define abs(x) (((x)<0)?-(x):(x))
int aa[105];
int up[105];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=60;i++)
    for(int j=0;j<16;j++)
    if(i%zs[j]==0)up[i]+=(1<<j);
    memset(f,63,sizeof f);
    f[0][0]=0;
    for(int i=0;i<=n-1;i++)
    for(int j=0;j<65536;j++)
    for(int k=1;k<=60;k++)
    {
            int u=(j|up[k]);
            if(!(j&up[k]))
            {
                    if(f[i][j]+abs(a[i+1]-k)<f[i+1][u])
                    {
                                                       pre[i+1][u]=j;
                                                       lj[i+1][u]=k;
                                                       f[i+1][u]=f[i][j]+abs(a[i+1]-k);
                                                       }
                    }}
    int ans=2100000000;int uu=0;
    for(int i=0;i<65536;i++)if(f[n][i]<ans){ans=f[n][i];uu=i;}
    for(int i=n;i>=1;i--)
    {
            aa[i]=lj[i][uu];
            uu=pre[i][uu];
            }
    for(int i=1;i<=n;i++)printf("%d ",aa[i]);
    return 0;
}