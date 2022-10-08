#include<cstdio>
#define mo 51123987
inline int abs(int a){return a>=0?a:-a;}
char s[200];
int f[151][52][52][52],g[151][3],n;
int main()
{
    scanf("%d%s",&n,s);
    g[n][0]=g[n][1]=g[n][2]=n;
    for(int i=n-1;i>=0;i--)
        g[i][0]=g[i+1][0],g[i][1]=g[i+1][1],g[i][2]=g[i+1][2],g[i][s[i]-'a']=i;
    f[0][0][0][0]=1;
    int m=(n+2)/3+1,s=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                for(int l=0;l<m;l++)
                    if(f[i][j][k][l])
                    {
                        if(j+k+l==n&&abs(j-k)<=1&&abs(k-l)<=1&&abs(l-j)<=1)
                            s=(s+f[i][j][k][l])%mo;
                        if(g[i][0]!=n)
                            f[g[i][0]][j+1][k][l]=(f[g[i][0]][j+1][k][l]+f[i][j][k][l])%mo;
                        if(g[i][1]!=n)
                            f[g[i][1]][j][k+1][l]=(f[g[i][1]][j][k+1][l]+f[i][j][k][l])%mo;
                        if(g[i][2]!=n)
                            f[g[i][2]][j][k][l+1]=(f[g[i][2]][j][k][l+1]+f[i][j][k][l])%mo;
                    }
    printf("%d\n",s);
    return 0;
}