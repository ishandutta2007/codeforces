#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143


using namespace std;

int m,n,k,x,y,a[1002][1002],r[1002],c[1002];
char ch;

int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=m;i++) r[i]=i;
    for (int i=1;i<=n;i++) c[i]=i;
    scanf("%c",&ch);
    for (int i=1;i<=k;i++)
    {
        scanf("%c",&ch);
        if (ch=='c')
        {
            scanf("%d %d",&x,&y);swap(c[x],c[y]);
        }
        else
        {
            if (ch=='r')
            {
                scanf("%d %d",&x,&y);swap(r[x],r[y]);
            }
            else
            {
                scanf("%d %d",&x,&y);printf("%d\n",a[r[x]][c[y]]);
            }
        }
        scanf("%c",&ch);
    }
    return 0;
}