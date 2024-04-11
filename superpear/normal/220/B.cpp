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

#define maxlongint 2147483647

using namespace std;

const int maxn=120000;

struct two2
{
    int num,place;
};

int m,n,o,e,a[maxn],b[maxn],f[maxn],ans,cs,lou[550][maxn];

int main()
{
    int x1,y1;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) b[i]=a[i];
    sort(b+1,b+n+1);
    o=0;
    e=1;
    for (int i=2;i<=n;i++)
        if (b[i]==b[i-1]) e++; else
        {
            if (b[i-1]<=e)
            {
                o++;f[o]=b[i-1];
            }
            e=1;
        }
    if (b[n]<=e)
    {
        o++;f[o]=b[n];
    }
    for (int i=1;i<=o;i++)
    {
        lou[i][0]=0;
        for (int j=1;j<=n;j++)
            if (f[i]==a[j]) lou[i][j]=lou[i][j-1]+1; else lou[i][j]=lou[i][j-1];
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&x1,&y1);
        ans=0;
        for (int j=1;j<=o;j++)
            if (f[j]==lou[j][y1]-lou[j][x1-1]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}