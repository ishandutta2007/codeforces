#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    long long a[107];
    int i;
    scanf("%d",&n);
    long long ans=0;
    for(i=1;i<=n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    for(i=1;i<=n;i++)
        {
        ans=ans+(a[i]-1)*i+1;
        }
    printf("%I64d\n",ans);
    return 0;
    }