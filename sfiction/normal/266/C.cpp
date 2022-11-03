/*
ID: Sfiction
OJ: CF
PROB: 266C
*/
#include <cstdio>
const int MAXN=1000;
int row[MAXN+1],col[MAXN+1];
int f[MAXN][2];
int act[MAXN*2][3];
int n,m;
void Move(int x)
{
    int i,j;
    for (i=x;i;--i)
        if (!col[i]) break;
    if (i<x)
    {
        act[m][0]=2;
        act[m][1]=i;
        act[m][2]=x;
        ++m;
        j=col[i];
        col[i]=col[x];
        col[x]=j;
        for (j=1;j<n;++j)
            if (f[j][0]<=x&&f[j][1]==x) f[j][1]=i;
    }
    for (i=x;i;--i)
        if (row[i]) break;
    if (!i) return;
    if (i<x)
    {
        act[m][0]=1;
        act[m][1]=i;
        act[m][2]=x;
        ++m;
        j=row[i];
        row[i]=row[x];
        row[x]=j;
        for (j=1;j<n;++j)
            if (f[j][0]==i||f[j][0]==x) f[j][0]=x+i-f[j][0];
    }
    for (j=1;j<n;++j)
        if (f[j][0]==x) --col[f[j][1]];
}
int main()
{
    int i;
    scanf("%d",&n);
    for (i=1;i<n;++i)
    {
        scanf("%d%d",&f[i][0],&f[i][1]);
        ++row[f[i][0]];
        ++col[f[i][1]];
    }
    for (i=n;i>1;--i) Move(i);
    printf("%d",m);
    for (i=0;i<m;++i) printf("\n%d %d %d",act[i][0],act[i][1],act[i][2]);
    return 0;
}