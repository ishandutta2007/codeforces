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

int m,n,flag,s,e;
int a[200][200],hang[200],lie[200];

int main()
{
    scanf("%d %d",&m,&n);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    memset(hang,0,sizeof(hang));
    memset(lie,0,sizeof(lie));
    while (true)
    {
        flag=1;
        for (int i=1;i<=m;i++)
        {
            s=0;
            for (int j=1;j<=n;j++) s+=a[i][j];
            if (s<0)
            {
                flag=0;
                for (int j=1;j<=n;j++) a[i][j]=-a[i][j];
                ++hang[i];
                break;
            }
        }
        if (flag==1)
        {
            for (int i=1;i<=n;i++)
            {
                s=0;
                for (int j=1;j<=m;j++) s+=a[j][i];
                if (s<0)
                {
                    flag=0;
                    for (int j=1;j<=m;j++) a[j][i]=-a[j][i];
                    ++lie[i];
                    break;
                }
            }
        }
        if (flag==1) break;
    }
    for (int i=1;i<=m;i++) hang[i]%=2;
    for (int i=1;i<=n;i++) lie[i]%=2;
    e=0;
    for (int i=1;i<=m;i++) e+=hang[i];
    printf("%d",e);
    for (int i=1;i<=m;i++) if (hang[i]==1) printf(" %d",i);
    printf("\n");
    e=0;
    for (int i=1;i<=n;i++) e+=lie[i];
    printf("%d",e);
    for (int i=1;i<=n;i++) if (lie[i]==1) printf(" %d",i);
    printf("\n");

    return 0;
}