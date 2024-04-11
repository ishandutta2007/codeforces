#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    int a[100007];
    int i;
    int l[100007];
    int r[100007];
    int x,y;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    l[0]=1;
    for(i=1;i<n;i++)
        {
        if(a[i]<=a[i-1])
            {
            l[i]=l[i-1]+1;
            }
        else l[i]=1;
        }
    r[n-1]=1;
    for(i=n-2;i>=0;i--)
        {
        if(a[i]<=a[i+1])
            {
            r[i]=r[i+1]+1;
            }
        else r[i]=1;
        }
    /*
    for(i=0;i<n;i++)
        {
        printf("%d ",l[i]);
        }
    printf("\n");
    for(i=0;i<n;i++)
        {
        printf("%d ",r[i]);
        }
    printf("\n");
    */
    int f,g;
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&x,&y);
        x--;
        y--;
        f=l[y];
        g=r[x];
        if(g+f<(y-x+1))printf("No\n");
        else printf("Yes\n");
        }
    return 0;
    }