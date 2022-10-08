#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 1000000007
const int d[2]={1,-1};
int f[110][52][2],g[110][52][2];char s[110];int n,m;
int main()
{
    scanf("%s%d",s,&m),n=strlen(s);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            f[i][j][0]=f[i][j][1]=-INF,
            g[i][j][0]=g[i][j][1]=INF;
    f[0][0][0]=g[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<2;k++)
            {
                if(f[i][j][k]>=-INF+200)
                {
                    int x=f[i][j][k],k2=k;
                    if(s[i]=='T')k2=!k;else x+=d[k];
                    f[i+1][j][k2]=max(f[i+1][j][k2],x),
                    g[i+1][j][k2]=min(g[i+1][j][k2],x);
                    if(j<m)
                    {
                        x=f[i][j][k],k2=k;
                        if(s[i]=='T')x+=d[k];else k2=!k;
                        f[i+1][j+1][k2]=max(f[i+1][j+1][k2],x),
                        g[i+1][j+1][k2]=min(g[i+1][j+1][k2],x);
                    }
                }
                if(g[i][j][k]<=INF-200)
                {
                    int x=g[i][j][k],k2=k;
                    if(s[i]=='T')k2=!k;else x+=d[k];
                    f[i+1][j][k2]=max(f[i+1][j][k2],x),
                    g[i+1][j][k2]=min(g[i+1][j][k2],x);
                    if(j<m)
                    {
                        x=g[i][j][k],k2=k;
                        if(s[i]=='T')x+=d[k];else k2=!k;
                        f[i+1][j+1][k2]=max(f[i+1][j+1][k2],x),
                        g[i+1][j+1][k2]=min(g[i+1][j+1][k2],x);
                    }
                }
            }
    int S=0;
    for(int i=m;i>=0;i-=2)S=max(S,max(max(f[n][i][0],f[n][i][1]),max(-g[n][i][0],-g[n][i][1])));
    printf("%d\n",S);
    return 0;
}