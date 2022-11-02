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

char ch;
int n,k,flag,minc,mink,o,f[500002][28],a[500002],g[500002][28],ans[500002];

int main()
{
    scanf("%d %d\n",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%c",&ch);
        a[i]=ch-64;
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<=26;j++)
            f[i][j]=maxlongint;
    f[0][0]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<=k;j++)
           if (f[i][j]!=maxlongint)
           {
              for (int c=1;c<=k;c++)
                  if (c!=j)
                  {
                      if (c==a[i+1]) flag=0; else flag=1;
                      if (f[i][j]+flag<f[i+1][c])
                      {
                          f[i+1][c]=f[i][j]+flag;
                          g[i+1][c]=j;
                      }
                  }
           }
    minc=maxlongint;mink=0;
    for (int i=1;i<=k;i++)
        if (f[n][i]<minc)
        {
            minc=f[n][i];
            mink=i;
        }
    printf("%d\n",minc);
    o=mink;
    for (int i=n;i>=1;i--)
    {
        ans[i]=o;
        o=g[i][o];
    }
    for (int i=1;i<=n;i++) printf("%c",ans[i]+64);
    printf("\n");
    return 0;
}