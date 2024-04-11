/*
ID: Sfiction
OJ: CF
PROB: 334B
*/
#include <cstdio>
const int n=7;
int a[8],b[8];
int Check()
{
    if (a[0]!=a[1]||a[0]!=a[2]) return 0;
    if (a[3]!=a[4]) return 0;
    if (a[5]!=a[6]||a[5]!=a[7]) return 0;
    if (b[0]!=b[3]||b[0]!=b[5]) return 0;
    if (b[1]!=b[6]) return 0;
    if (b[2]!=b[4]||b[2]!=b[7]) return 0;
    if (a[0]>=a[3]||a[3]>=a[5]) return 0;
    if (b[0]>=b[1]||b[1]>=b[2]) return 0;
    return 1;
}
void swap(int x,int y)
{
    int t;
    t=a[x];
    a[x]=a[y];
    a[y]=t;
    t=b[x];
    b[x]=b[y];
    b[y]=t;
}
int Arrange(int x)
{
    int i;
    if (x==n) return Check();
    for (i=x;i<=n;++i)
    {
        swap(x,i);
        if (Arrange(x+1)) return 1;
        swap(x,i);
    }
    return 0;
}
int main()
{
    int i;
    for (i=0;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
    if (Arrange(0)) printf("respectable");
    else printf("ugly");
    return 0;
}