# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <queue>
# include <algorithm>
using namespace std;
int a[100000][10];
int b[100000][10];
int c[10];
int ans[100000];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            scanf("%d",&a[i][x]);
        }
    }
    for (int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        c[y-1]++;
        b[x-1][y-1]++;
    }
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            if (a[i][x]>0)
            {
                ans[i]+=c[x]-b[i][x];
            }
        }
        printf("%d ",ans[i]);
    }
    printf("\n");
}