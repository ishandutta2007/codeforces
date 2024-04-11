#include<stdio.h>
#include<cstring>
#define MAXN 410000
using namespace std;
int f[2][MAXN][2];
int sumh[205];
int h[205];
int a,b;
int n;
void MIN(int &x,int y)
{
     if(y<0)return;
     if(x<0)x=y;
     else if(x>y)x=y;
}
int min(int x,int y){if(x<y)return x;return y;}
int main()
{
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    scanf("%d",&n);scanf("%d%d",&a,&b);
    for(int i=1;i<=n;i++){scanf("%d",&h[i]);sumh[i]=h[i]+sumh[i-1];}
    for(int j=0;j<=a;j++)
    f[0][j][0]=f[0][j][1]=f[1][j][0]=f[1][j][1]=-2100000000;
    f[0][0][0]=0;int now=0;
    for(int i=1;i<=n;i++){now^=1;
    for(int j=0;j<=a;j++)
    f[now][j][0]=f[now][j][1]=-2100000000;
    for(int j=0;j<=a;j++)
    {
            if(j>=h[i])
            {
                       MIN(f[now][j][1],f[now^1][j-h[i]][0]+min(h[i],h[i-1]));
                       MIN(f[now][j][1],f[now^1][j-h[i]][1]);
                       }
            if(sumh[i]-j<=b)
            {
                            MIN(f[now][j][0],f[now^1][j][1]+min(h[i],h[i-1]));
                            MIN(f[now][j][0],f[now^1][j][0]);
                            }
                            }
                            }
    int ans=-1;
    for(int j=0;j<=a;j++)
    {
            MIN(ans,f[now][j][0]);
            MIN(ans,f[now][j][1]);
            }
    printf("%d\n",ans);
    return 0;
}