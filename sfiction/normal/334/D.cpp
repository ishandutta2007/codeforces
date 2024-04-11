/*
ID: Sfiction
OJ: CF
PROB: 334D
*/
#include <cstdio>
#include <cstring>
const int MAXN=1000;
char row[MAXN+1],col[MAXN+1];
int main()
{
    int n,m;
    int i,x,y;
    int sum;
    scanf("%d%d",&n,&m);
    memset(row+1,1,n);
    memset(col+1,1,n);
    for (i=0;i<m;++i)
    {
        scanf("%d%d",&x,&y);
        row[x]=0;
        col[y]=0;
    }
    if ((n&1)&&(row[n/2+1]|col[n/2+1])) sum=1;
    else sum=0;
    for (i=2;i<=n/2;++i) sum+=row[i]+row[n-i+1]+col[i]+col[n-i+1];
    printf("%d",sum);
    return 0;
}