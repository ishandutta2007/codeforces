/*
ID: Sfiction
OJ: TC
PROB: 275B
*/
#include <cstdio>
const int MAXN=100;
char a[MAXN][MAXN];
int b[MAXN][2];
int Work()
{
    int i,j,k,N,M;
    int l,r;
    scanf("%d%d",&N,&M);
    for (i=0;i<N;++i) scanf("%s",a[i]);
    for (i=0;i<N;++i)
    {
        for (l=0;l<M&&a[i][l]=='W';++l);
        for (r=M-1;r>=0&&a[i][r]=='W';--r);
        for (j=l;j<=r&&a[i][j]=='B';++j);
        if (j<=r) return 0;
    }
    for (j=0;j<M;++j)
    {
        for (l=0;l<N&&a[l][j]=='W';++l);
        for (r=N-1;r>=0&&a[r][j]=='W';--r);
        for (i=l;i<=r&&a[i][j]=='B';++i);
        if (i<=r) return 0;
    }
    for (i=0;i<N;++i)
        for (j=0;j<M;++j)
            for (k=0;k<N;++k)
                for (l=0;l<M;++l)
                    if (a[i][j]=='B'&&a[k][l]=='B'&&a[i][l]=='W'&&a[k][j]=='W') return 0;
    return 1;
}
int main()
{
    if (Work()) printf("YES");
    else printf("NO");
    return 0;
}