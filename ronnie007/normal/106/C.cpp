#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int f[1007];

int main()
    {
    int n,m;
    int a,b,c,d;
    int i,j,k;
    int c0,d0;
    scanf("%d%d%d%d",&n,&m,&c0,&d0);
    for (i=c0;i<=n;i++)
        {
        f[i]=f[i-c0]+d0;
        }
    for (i=0;i<m;i++)
        {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for (j=0;j<a/b;j++)
            {
            for (k=n;k>=c;k--)
                {
                f[k]=max(f[k],f[k-c]+d);
                }
            }
        }
    printf("%d\n",f[n]);
    return 0;
    }