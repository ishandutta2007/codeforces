#include<stdio.h>
#include<cstring>
#define MAXN 1005
using namespace std;
char str[MAXN][MAXN];
int tot[MAXN];
int n,m,x,y;
int f[1005][1005][2];
void Min(int &a,int b){if(b<a)a=b;}
void Max(int &a,int b){if(b>a)a=b;}
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);Max(x,1);Min(y,m);
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    tot[j]+=(str[i][j]=='#');
    memset(f,63,sizeof f);
    f[1][1][0]=tot[1];
    f[1][1][1]=n-tot[1];
    for(int i=1;i<m;i++)
    for(int l=1;l<=y;l++)
    {
            if(l+1<=y)
            {
                  Min(f[i+1][l+1][0],f[i][l][0]+tot[i+1]);
                  Min(f[i+1][l+1][1],f[i][l][1]+n-tot[i+1]);
            }
            if(l<=y&&l>=x)
            {
                          Min(f[i+1][1][1],f[i][l][0]+n-tot[i+1]);
                          Min(f[i+1][1][0],f[i][l][1]+tot[i+1]);
                          }}
    int ans=2100000000;
    for(int i=x;i<=y;i++)
    Min(ans,f[m][i][0]),Min(ans,f[m][i][1]);
    printf("%d\n",ans);
    return 0;
}