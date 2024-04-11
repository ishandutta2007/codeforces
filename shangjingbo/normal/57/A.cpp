#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define inf 1000000000

int n,d[10][10];
struct node
{
    int x,y;
}a[10];

int main()
{
    for (int i=0;i<6;++i)
    {
        for (int j=0;j<6;++j)
            d[i][j]=inf;
        d[i][i]=0;
    }
    
    scanf("%d",&n);
    a[0].x=0;a[0].y=0;
    a[1].x=0;a[1].y=n;
    a[2].x=n;a[2].y=n;
    a[3].x=n;a[3].y=0;
    for (int i=4;i<6;++i)
        scanf("%d%d",&a[i].x,&a[i].y);
    
    for (int i=0;i<6;++i)
        for (int j=0;j<6;++j)
            for (int k=0;k<4;++k)
            if (a[i].x==a[k].x && a[j].x==a[k].x || a[i].y==a[j].y && a[i].y==a[k].y)
                d[i][j]=d[j][i]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
    
    for (int k=0;k<6;++k)
        for (int i=0;i<6;++i)
            for (int j=0;j<6;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    
    printf("%d\n",d[4][5]);
    
    return 0;
}