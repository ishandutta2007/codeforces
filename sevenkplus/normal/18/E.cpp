#include<cstdio>
int f[510][30][30],fx[510][30][30],fy[510][30][30],b[2][510][30],n,m,p[30][30],px[30][30],py[30][30];
char a[510][510];
char s[510];
#define Max 1000000009
inline int min(int a,int b){return a<b?a:b;}
inline void Calc(int i,int x,int y,int dx,int dy)
{
    p[x][y]=f[i-1][x][y],px[x][y]=x,py[x][y]=y;
    if(0<=x+dx&&x+dx<26&&p[x+dx][y]<p[x][y])
        p[x][y]=p[x+dx][y],px[x][y]=px[x+dx][y],py[x][y]=py[x+dx][y];
    if(0<=y+dy&&y+dy<26&&p[x][y+dy]<p[x][y])
        p[x][y]=p[x][y+dy],px[x][y]=px[x][y+dy],py[x][y]=py[x][y+dy];
}
inline void Calc(int i,int dx,int dy)
{
    for(int x=0;x<26;x++)
        for(int y=0;y<26;y++)
            if(x!=y&&0<=x+dx&&x+dx<26&&0<=y+dy&&y+dy<26)
                if(p[x+dx][y+dy]+m-b[0][i][x]-b[1][i][y]<f[i][x][y])
                    f[i][x][y]=p[x+dx][y+dy]+m-b[0][i][x]-b[1][i][y],
                    fx[i][x][y]=px[x+dx][y+dy],
                    fy[i][x][y]=py[x+dx][y+dy];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            b[j&1][i][s[j]-'a']++;
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(i==j)
                f[0][i][j]=Max;
            else
                f[0][i][j]=m-b[0][0][i]-b[1][0][j];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                f[i][j][k]=Max;
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                Calc(i,j,k,-1,-1);
        Calc(i,-1,-1);
        for(int j=25;j>=0;j--)
            for(int k=0;k<26;k++)
                Calc(i,j,k,+1,-1);
        Calc(i,+1,-1);
        for(int j=0;j<26;j++)
            for(int k=25;k>=0;k--)
                Calc(i,j,k,-1,+1);
        Calc(i,-1,+1);
        for(int j=25;j>=0;j--)
            for(int k=25;k>=0;k--)
                Calc(i,j,k,+1,+1);
        Calc(i,+1,+1);
    }
    int I,J,S=Max;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(f[n-1][i][j]<S)
                S=f[n-1][i][j],I=i,J=j;
    printf("%d\n",S);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
            if(j&1)
                a[i][j]=J+'a';
            else
                a[i][j]=I+'a';
        int X=fx[i][I][J],Y=fy[i][I][J];
        I=X,J=Y;
    }
    for(int i=0;i<n;i++)
        puts(a[i]);
    return 0;
}