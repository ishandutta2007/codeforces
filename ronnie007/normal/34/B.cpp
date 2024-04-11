#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
    {
    int n,m;
    int a[127];
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        a[i]=0-a[i];
        }
    sort(a,a+n);
    int br=0;
    int ans=0;
    for(i=n-1;i>=0;i--)
        {
        if(a[i]<0)break;
        if(br==m)break;
        ans+=a[i];
        br++;
        }
    printf("%d\n",ans);
    return 0;
    }