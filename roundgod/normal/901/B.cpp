#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[150],b[150],c[150];
int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[0]=1;
    b[1]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            c[j]=b[j];
        for(int j=n;j>=0;j--)
            b[j]=j==0?a[j]:b[j-1]+a[j];
        for(int j=0;j<=n;j++)
            a[j]=c[j];
    }
    printf("%d\n",n);
    for(int j=0;j<=n;j++)
    {
        if(b[j]%2==0) printf("0 ");
        else if(b[j]%4==1) printf("1 ");
        else printf("-1 ");
    }
    printf("\n");
    printf("%d\n",n-1);
    for(int j=0;j<=n-1;j++)
    {
        if(a[j]%2==0) printf("0 ");
        else if(a[j]%4==1) printf("1 ");
        else printf("-1 ");
    }
    return 0;
}