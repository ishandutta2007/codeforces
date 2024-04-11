#include<stdio.h>
#include<cstring>
using namespace std;
int f[601][301][301];
int a[301][301];
int dx[3]={0,-1,0};
int dy[3]={0,0,-1};
#define max(a,b) ((a)<(b)?(b):(a))
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    for(int i=0;i<=2*n-2;i++)
    for(int j=0;j<=i;j++)
    for(int k=0;k<=i;k++)
    f[i][j][k]=-1000000000;
    f[0][0][0]=a[n][n];
    for(int i=0;i<=2*n-3;i++)
    for(int j=0;j<=i;j++)
    for(int k=0;k<=i;k++)
    for(int k1=1;k1<=2;k1++)
    for(int k2=1;k2<=2;k2++)
    {
            int x1,y1,x2,y2;
            x1=n-j;y1=n-(i-j);
            x2=n-k;y2=n-(i-k);
            x1+=dx[k1];y1+=dy[k1];
            x2+=dx[k2];y2+=dy[k2];
            if(x1<1||y1<1||x2<1||y2<1)continue;
            if(x1==x2&&y1==y2)f[i+1][j-dx[k1]][k-dx[k2]]=max(f[i+1][j-dx[k1]][k-dx[k2]],f[i][j][k]+a[x1][y1]);
            else f[i+1][j-dx[k1]][k-dx[k2]]=max(f[i+1][j-dx[k1]][k-dx[k2]],f[i][j][k]+a[x1][y1]+a[x2][y2]);
            }
    printf("%d\n",f[2*n-2][n-1][n-1]);
    return 0;
}