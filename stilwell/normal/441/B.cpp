#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define mk make_pair
using namespace std;
int i,j,k,l,n,m,sum,an;
const int N=5100;
class arr
{
    public:
        int x,y;
}a[N];
bool com(const arr &o,const arr &p)
{
    return o.x<p.x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
    sort(&a[1],&a[n+1],com);
    for (int t=1;t<=a[n].x+1;t++)
    {
        int v=0;
        for (int j=1;j<=n;j++)
        if ((a[j].y)&&(a[j].x==t-1))
        {
            if (v+a[j].y<=m) v+=a[j].y,a[j].y=0;
            else a[j].y-=(m-v),v=m;
        }
        for (int j=1;j<=n;j++)
        if ((a[j].y)&&(a[j].x==t))
        {
            if (v+a[j].y<=m) v+=a[j].y,a[j].y=0;
            else a[j].y-=(m-v),v=m;
        }
        an+=v;
    }
    printf("%d\n",an);
    //system("pause");
    return 0;
}